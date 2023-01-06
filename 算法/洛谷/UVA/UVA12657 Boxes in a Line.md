# 移动盒子 Boxes in a Line

>  题目描述

你有n个盒子在桌子上的一条线上从左到右编号为1……n。你的任务是模拟四种操作

1 X Y 移动盒子编号X到盒子编号Y的左边（如果X已经在Y的左边了就忽略）

2 X Y 移动盒子编号X到盒子编号Y的右边（如果X已经在Y的右边了就忽略）

3 X Y 交换盒子编号X与盒子编号Y的位置

4 将整条线反转

操作保证合法，X不等于Y

举一个例子，如果n=6，操作 1 1 4然后就变成了2 3 1 4 5 6；再操作 2 3 5就变成了 2 1 4 5 3 6；再操作 3 1 6 就变成 2 6 4 5 3 1；最后操作4，就变成了 1 3 5 4 6 2

输入

最多有10组数据，每个数据会包含两个整数n,m（1≤n,m<100,000）, 接下来是m行数据，表示操作。

输出

对于每组数据，输出他们奇数位置的编号的和。

> 解题思路

双链表模拟

```c++
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
```

