#include <iostream>
using namespace std;

// %1000再/10，依次类推即可，但是其过于池沼没有输出No（无能）
// 这么看来枚举暴力其是完完全全的新手 

int main() {
	int k;
	int a, b, c, t;
	bool flag = false;
	cin >> k;
	for (int i = 10000; i <= 30000; i++) {
		t = i;
		a = t % 1000;
		t /= 10;
		b = t % 1000;
		t /= 10;
		c = t;
		if (!(a % k) && !(b % k) && !(c % k)) cout << i << endl, flag = true;
	}
	if (!flag) cout << "No";
	return 0;
}
