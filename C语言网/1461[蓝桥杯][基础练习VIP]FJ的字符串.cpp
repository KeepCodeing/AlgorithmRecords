#include <iostream>
#include <cstdio>
using namespace std;

// 找规律...，可以看成后一个字符由前一个字符+i+前一个字符组成 

int main() {
	int n;
	cin >> n;
	string res = "";
	for (int i = 0; i < n; i++) {
		res += (char)('A' + i) + res;
	}
	cout << res;
	return 0;
}
