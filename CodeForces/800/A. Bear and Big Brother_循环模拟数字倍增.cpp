#include <iostream>
using namespace std;

// 熊和老大哥ww，有意思的title w，题意就是a熊每年增加3倍体重，b熊每年增加2倍，然后判断
// 要几年a > b... 

int main() {
	int a, b, cnt = 0;
	cin >> a >> b;
	while (true) {
		a *= 3, b *= 2, cnt++;
		if (a > b) break;
	}
	cout << cnt << endl;
	return 0;
}
