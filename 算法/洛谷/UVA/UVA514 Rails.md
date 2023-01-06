# UVA514 Rails

> 题目描述

某城市有一个火车站，铁轨铺设如图。有n节车厢从A方向驶入车站，按进站的顺序编号为1～n。你的任务是判断是否能让他们按照某种特定的顺序进入B方向的铁轨并驶出车站。例如，出栈顺序（5 4 1 2 3）是不可能的，但（5 4 3 2 1）是可能的。 为了重组车厢，你可以借助中转站C。这是一个可以停放任意多节车厢的车站，但由于末端封顶，驶入C的车厢必须按照相反的顺序驶出C。对于每节车厢，一旦从A移入C，就不能返回A了;一旦从C移入B，就不能返回C了。也就是说，在任意时刻，只有两种选择：A到C和C到B。

![](.\imgs\rails.png)

>输入格式

对于每一组数据，第一行是一个整数 N 。接下来若干行数据，每行 N个数，代表 1 ~ N 车厢的出栈顺序，最后一组数据只有一个整数 0。对于每一组数据，在最后输出空行。

最后一组数据的 N=0，不输出。

`n<=1000`

> 解题思路

这道题比较基本考察栈这种数据结构.

```c++
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define FEIL_OUTPUT
#ifdef FILE_OUTPUT
fstream
#endif
int N = 0;

bool check(int* nums);
int main(int argc, char **argv){
	while(true){
		cin >> N;
		if(N == 0){
			break;
		}
		int nums[N];
		bool flag = true;
		while(flag){
			for(int i = 0; i < N; i++){
				cin >> nums[i];
				if(nums[0] == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << (check(nums) ? "Yes" : "No") << endl;	
			}
		}
		cout << endl;
	}
	return 0;
}
bool check(int* nums){
	queue<int> A;
	stack<int> C;
	int p = 0;
	int i = 0;
	while(p < N){
		if(i == nums[p]){
			p++;
			i++;
		}else if(i < nums[p]){
			C.push(i);
			i++;
		}else{
			while(!C.empty() && C.top() == nums[p]){
				p++;
				C.pop();
			}
			if(!C.empty() && C.top() > nums[p]){
				return false;
			}
		}
	}
	return true;
}
```

