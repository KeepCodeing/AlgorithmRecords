#include <iostream>
using namespace std;
// 给出一个字符串A，判断另外一个字符串B是否被包含于其中
// 四种解法
// 1. 暴力， 2. map计数，3. 排序，4. 利用API（本文件解法） 
int main() {
	string A = "Hello World";
	string B = "World1";
	for (int i = 0; i < B.size(); i++) {
		// 使用find函数在A串里查找B串的所有字符 
		if (A.find(B[i]) == -1) {
			cout << "can not !" << endl;
			break;
		}
	}
	
	return 0;
} 
