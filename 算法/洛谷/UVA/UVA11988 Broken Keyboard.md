# 破损的键盘 Broken Keyboard

> 题目描述

你在输入文章的时候，键盘上的Home键和End键出了问题，会不定时的按下。你却不知道此问题，而是专心致志地打稿子，甚至显示器都没开。当你打开显示器之后，展现你面前的数一段悲剧文本。你的任务是在显示器打开前计算出这段悲剧的文本。
给你一段按键的文本，其中'['表示Home键，']'表示End键，输入结束标志是文件结束符（EOF）。

输出一行，即这段悲剧文本。

> 解题思路

使用链表

```c++
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
```