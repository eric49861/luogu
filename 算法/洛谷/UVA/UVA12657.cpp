#include <iostream>
using namespace std;
//#define DEBUG
void print();
void remove(int x);
void insertToRight(int x, int y);
void insertToLeft(int x, int y);
void exchange(int x, int y);
void printChain();

int _left[100002];
int _right[100002];
int n = 0, m = 0;
bool rev = false;

int main(int argc, char **argv){
	int op = 0;
	int count = 1;
	while(cin >> n >> m){
		for(int i = 0; i <= n; i++){
			_left[i] = i-1;
			_right[i] = i+1;
		}
#ifdef DEBUG
		printChain();
#endif
		while(m-- > 0){
			cin >> op;
			int x = 0;
			int y = 0;
			if(op == 1){
				//将 X 移到 Y 的左边 
				cin >> x >> y;
				if(rev){
					if(_left[x] == y){
						continue;
					}
				}else{
					if(_right[x] == y){
						continue;
					}
				}
				
				remove(x);
				if(rev){
					insertToRight(x, y);
				}else{
					insertToLeft(x, y);
				}
				
			}else if(op == 2){
				//将 X 移到 Y 的右边 
				cin >> x >> y;
				if(rev){
					if(_right[x] == y){
						continue;
					}
				}else{
					if(_left[x] == y){
						continue;
					}
				}
				remove(x);
				if(rev){
					insertToLeft(x, y);
				}else{
					insertToRight(x, y);
				}
			}else if(op == 3){
				//将 X 与 Y 互换
				cin >> x >> y;
				exchange(x, y);
			}else if(op == 4){
				//翻转序列
				rev = !rev;
			}
		}
		unsigned int sum = 0;
		int head = 0;
		bool odd = rev ? (n % 2 == 0 ? false : true) : true;
		
		
		for(int i = 0; i < n; i++){
			sum += (odd ? _right[head] : 0);
			head = _right[head];
			odd = !odd;
		}
		
		cout << "Case " << count << ": " << sum << endl;
		count++;
		rev = false;
	}
	return 0;
}

void printChain(){
	int head = 0;
	for(int i = 0; i < n; i++){
		head = _right[head];
		cout << head << " ";
	}
	cout << endl;
}
void print(){
	for(int i = 0; i <= n+1; i++){
		cout << _left[i] << " ";
	}
	cout << endl;
	for(int i = 0; i <= n+1; i++){
		cout << _right[i] << " ";
	}
	cout << endl;
}
void remove(int x){
	int l = _left[x];
	int r = _right[x];
	_right[l] = r;
	_left[r] = l;
//#ifdef DEBUG
//	printChain();
//#endif
}

void insertToRight(int x, int y){
	int tmp = _right[y];
	_right[y] = x;
	_left[x] = y;
	_right[x] = tmp;
	_left[tmp] = x;
	
#ifdef DEBUG
	printChain();
#endif
}
void insertToLeft(int x, int y){
	int tmp = _left[y];
	_left[y] = x;
	_right[x] = y;
	_left[x] = tmp;
	_right[tmp] = x;
	
#ifdef DEBUG
	printChain();
#endif
}

void exchange(int x, int y){
	if(_left[x] == y){
		remove(x);
		insertToLeft(x, y);
		return;
	}else if(_right[x] == y){
		remove(x);
		insertToRight(x, y);
		return;
	}
	int xr = _right[x];
	int xl = _left[x];
	int yr = _right[y];
	int yl = _left[y];
	_right[xl] = y;
	_left[y] = xl;
	_left[xr] = y;
	_right[y] = xr;
	
	_right[yl] = x;
	_left[x] = yl;
	_left[yr] = x;
	_right[x] = yr;
	
#ifdef DEBUG
	printChain();
#endif
}
