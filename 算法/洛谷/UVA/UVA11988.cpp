#include <iostream>
#include <list>
using namespace std;

void beiju(string& text);

int main(int argc, char **argv){
	string text;
	while(cin >> text){
		beiju(text);
	}
	return 0;
}

void beiju(string& text){
	list<char> result;
	int length = text.length();
	bool home = false;
	int count = 0;
	for(int i = 0; i < length; i++){
		if(text[i] == '['){
			home = true;
			count = 0;
		}else if(text[i] == ']'){
			home = false;
		}else{
			if(home){
				result.insert(next(result.begin(), count), text[i]);
				count++;
			}else{
				result.insert(result.end(), text[i]);
			}
		}
	}
	for(const char c : result){
		cout << c;
	}
	cout << endl;
}
