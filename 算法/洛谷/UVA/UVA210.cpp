#include <deque>
#include <queue>
#include <string>
#include <map>
#include <iostream>
using namespace std;

typedef struct Program{
	int id;
	int point;
	string statements[30];
	
	Program(int id, int point):id(id), point(point){}
} Program;

void algo();

int n = 0;
int t1, t2, t3, t4, t5;
int Q = 0;

int main(int argc, char **argv)
{
	int times = 0;
	cin >> times;
	for(int i = 0; i < times; i++){
		cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
		getchar();
		algo();
		if(i != times-1){
			cout << endl;
		}
	}
	return 0;
	
}
void algo(){
	deque<Program> wait;
	queue<Program> stop;
	map<char, string> vars;
	string end = "end";
	for(int i = 0; i < n; i++){
		Program program(i, 0);
		string statement;
		int count = 0;
		while(end.compare(statement) != 0){
			getline(cin, statement);
			program.statements[count++] = statement;
		}
		wait.push_back(program);
	}
	int lock = 0;
	while(!wait.empty()){
		Program p = wait.front();
		wait.pop_front();
		bool finished = false;
		bool stopped = false;
		int t = Q;
		while(t > 0){
			string s = p.statements[p.point];
			p.point++;
			if(s.compare("lock") == 0){
				if(lock == 1){
					stopped = true;
					p.point--;
					stop.push(p);
					break;
				}else{
					lock = 1;
					t -= t3;
				}
			}else if(s.compare("unlock") == 0){
				if(!stop.empty()){
					Program sp = stop.front();
					stop.pop();
					wait.push_front(sp);
				}
				t -= t4;
				lock = 0;
			}else if(s.substr(0, 5).compare("print") == 0){
				t -= t2;
				cout << p.id+1 << ": " << (vars[s[6]].compare("") == 0 ? "0" : vars[s[6]]) << endl;
			}else if(s.compare("end") == 0){
				finished = true;
				t -= t5;
				break;
			}else{
				vars[s[0]] = s.substr(4);
				t -= t1;
			}
		}
		if(!stopped && !finished){
			wait.push_back(p);
		}
	}
}
