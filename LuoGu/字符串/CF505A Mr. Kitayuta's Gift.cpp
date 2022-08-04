#include <iostream>
using namespace std;
// 手写一个swap函数，当然也可以用algorithm里的 
void sp(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
// 双指针旋转字符串 
bool solve(string str) {
	string temp = str;
	// 定义左右指针的位置 
	int l = 0, r = str.size() - 1;
	// 指针对撞 
	while (l < r) sp(temp[l++], temp[r--]);
	// 如果是回文字符串，就说明产生了一个答案 
	return str == temp;
}
int main() {
	string str;
	cin >> str;
	string temp;
	int sLen = str.size();
	// 在每个位置枚举可以插入的字符 
	for (char i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j <= sLen; j++) {
			temp = str;
			// insert方法可以在j这个位置插入长度为1的字符i 
			temp.insert(j, 1, i); 
			// 产生了答案直接退出 
			if (solve(temp)) {
				cout << temp << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}
