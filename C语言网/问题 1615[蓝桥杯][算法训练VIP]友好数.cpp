#include <iostream>
using namespace std;

int ys(int x) {
	int res = 0;
	for (int i = 1; i <= x / i; i++) {
		if (!(x % i)) {
			res += i;
			// 题目要求约数不算自己，所以要忽略掉这种情况（也就是i=1时） 
			if (i != x / i && x != x / i) res += x / i;
		}
	}
	return res;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a == ys(b) && ys(a) == b) cout << "yes";
	else cout << "no"; 
	return 0;
}
