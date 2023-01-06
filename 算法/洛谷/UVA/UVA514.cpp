#include <iostream>
#include <stack>
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
