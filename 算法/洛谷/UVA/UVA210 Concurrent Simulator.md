# UVA210 Concurrent Simulator

> 题目描述

你的任务是模拟n个程序（按输入顺序编号为1～n）的并行执行。每个程序包含不超过 25条语句，格式一共有5种：var = constant（赋值）；print var（打印）；lock；unlock；end。 

变量用单个小写字母表示，初始为0，为所有程序公有（因此在一个程序里对某个变量 赋值可能会影响另一个程序）。常数是小于100的非负整数。 

每个时刻只能有一个程序处于运行态，其他程序均处于等待态。上述5种语句分别需 要t1、t2、t3、t4、t5单位时间。运行态的程序每次最多运行Q个单位时间（称为配额）。当 一个程序的配额用完之后，把当前语句（如果存在）执行完之后该程序会被插入一个等待队 列中，然后处理器从队首取出一个程序继续执行。初始等待队列包含按输入顺序排列的各个 程序，但由于lock/unlock语句的出现，这个顺序可能会改变。 

lock的作用是申请对所有变量的独占访问。lock和unlock总是成对出现，并且不会嵌套。 lock总是在unlock的前面。当一个程序成功执行完lock指令之后，其他程序一旦试图执行lock 指令，就会马上被放到一个所谓的阻止队列的尾部（没有用完的配额就浪费了）。当unlock 执行完毕后，阻止队列的第一个程序进入等待队列的首部。

输入n, t1, t2, t3, t4, t5, Q以及n个程序，按照时间顺序输出所有print语句的程序编号和结 果。

> 解题思路

重点是理解题目,算法并不难,就是过程比较繁琐

```C++
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

```

