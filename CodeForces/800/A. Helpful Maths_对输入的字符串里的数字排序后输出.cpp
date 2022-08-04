#include <iostream>
using namespace std;

// 洛谷做过，现在那时候不知道怎么做的，总之只有三个数字，故而可以
// 用桶的思想把数字存起来然后输出 

int bucket[5];
int main() {
	char c;
	bool flag = false;
	while (cin >> c) {
		if (c != '+') bucket[c - '0']++;
	}
	for (int i = 1; i <= 3; i++) {
		while (bucket[i]--) {
			
			if (flag) cout << '+';
			cout << i, flag = true;
		}
	}
	return 0;
}
