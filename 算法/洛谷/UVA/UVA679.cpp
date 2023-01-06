
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	int cases = 0;
	cin >> cases;
	while(true){
		int D = 0;
		cin >> D;
		if(D == -1){
			break;
		}
		int I = 0;
		cin >> I;
		int index = 0;
		for(int i = 0; i < D; i++){
			if(2*index+1 >= (1<<D)-1){
				break;
			}
			if(I%2 == 0){
				//ÓÒ
				I = I / 2;
				index = 2 * index + 2;
			}else{
				//×ó 
				I = (I + 1) / 2;
				index = 2 * index + 1;
			}
			
		}
		cout << index+1 << endl;
	}
	return 0;
}
