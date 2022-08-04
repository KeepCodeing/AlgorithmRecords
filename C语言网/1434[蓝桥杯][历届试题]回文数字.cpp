#include <iostream>
using namespace std;

// 就是在判断回文数字的基础上加了个判断位数和 

// 又没看到不满足的情况输出-1，最幸福的人

int main() {
	int n;
	bool flag = false;
	cin >> n; 
	int sumT, t, tot;
	for (int i = 10000; i <= 999999; i++) {
		t = i, sumT = 0, tot = 0;
		while (t) {
			tot += t % 10;
			sumT = sumT * 10 + t % 10;
			t /= 10;
		}
		if (tot == n && sumT == i) cout << i << endl, flag = true;
	} 
	if (!flag) cout << -1;
	return 0;
} 
