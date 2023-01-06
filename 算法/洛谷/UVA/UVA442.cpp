#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

typedef struct Matrix{
	int rows;
	int cols;
	Matrix(){
	}
	Matrix(int rows, int cols):rows(rows), cols(cols){
	}
}Matrix;

map<string, Matrix> vars;

int compute(string& expression);

int main(int argc, char **argv){
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		string name;
		int rows;
		int cols;
		cin >> name >> rows >> cols;
		vars[name] = Matrix(rows, cols);
	}
	string expression;
	while(cin >> expression){
		int result = compute(expression);
		if(result == -1){
			cout << "error" << endl;
		}else{
			cout << result << endl;
		}
	}
	return 0;
}

int compute(string& expression){
	stack<string> symbols;
	int result = 0;
	int length = expression.length();
	if(length == 1){
		return result;
	}
	for(int i = 0; i < length; i++){
		string tmp = string(1, expression[i]);
		if(tmp == "("){
			symbols.push(tmp);
		}else if(tmp == ")"){
			string m[2];
			for(int j = 0; j < 2; j++){
				m[j] = symbols.top();
				symbols.pop();
			}
			symbols.pop();
			if(vars[m[1]].cols != vars[m[0]].rows){
				return -1;
			}
			Matrix right = vars[m[0]];
			Matrix left = vars[m[1]];
			result += left.rows * left.cols * right.cols;
			if(!symbols.empty()){
				Matrix mat = Matrix(left.rows, right.cols);
				string name = m[1]+m[0];
				vars[name] = mat;
				symbols.push(name);
			}else{
				return result;
			}
		}else{
			symbols.push(tmp);
		}
	}
}
