#include <iostream>
using namespace std;
int main() {
	// 模拟就完事了
	string a, b;
	cin >> a >> b;
	int aLen, bLen;
	aLen = a.size(), bLen = b.size();
	if (a == b) {
		cout << 2;
	} else if (aLen != bLen) {
		cout << 1;
	} else if (aLen == bLen) {
		bool flag = true;
		for (int i = 0; i < aLen; i++) {
			if (tolower(a[i]) != tolower(b[i])) flag = false;
		}
		cout << (flag ? 3 : 4);
	}
	
	return 0;
}
