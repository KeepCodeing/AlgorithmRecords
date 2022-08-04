#include <iostream>
using namespace std;

// 实现下高精加

string Add(string a, string b) {
	string result;
	int aLen, bLen;
	aLen = a.length(), bLen = b.length();
	int maxLen = max(aLen, bLen);
	for (int i = aLen; i < maxLen; i++) a = "0" + a;
	for (int i = bLen; i < maxLen; i++) b = "0" + b;
	int flag = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		char temp = a[i] + b[i] - '0' + flag;
		if (temp > '9') flag = 1, temp -= 10;
		else flag = 0;
		result = temp + result;
	}
	if (flag) result = "1" + result;
	return result;
}  

int main() {
	string a, b;
	cin >> a >> b;
	cout << Add(a, b);
	return 0;
}
