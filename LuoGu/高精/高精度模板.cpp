#include <iostream>
using namespace std;

// 高精算法的核心思想：主要还是模拟数学中的竖式运算，用数组
// 把数字的每一位都乘起来 

// 高精加 
string Add(string a, string b) {
	string result;
	// 获取长度 
	int aLen = a.length(), bLen = b.length();
	int maxLen = max(aLen, bLen);
	// 给较短的字符前补0，方便后面进行运算 
	for (int i = aLen; i < maxLen; i++) a = "0" + a;
	for (int i = bLen; i < maxLen; i++) b = "0" + b;
	// 判断是否进位 
	int flag = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		char temp = a[i] + b[i] - '0' + flag;
		if (temp > '9') flag = 1, temp -= 10;
		else flag = 0;
		// 因为是倒着运算的，所以要把加出来的高位放前面 
		result = temp + result;
	}
	// 判断最后是否要进行进位 
	if (flag) result = "1" + result;
	return result;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << Add(a, b);
	return 0;
}
