#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int t = 1, cnt = 1;
	int num;
	int res = -1e9, rCnt = 1;
	int maxCnt = 0;
	while (t <= n) {
		for (int i = 1; i <= t; i++) cin >> num, maxCnt += num;
		if (maxCnt > res) res = maxCnt, rCnt = cnt;
		cnt++;
		t <<= 1;
		maxCnt = 0;
	}
	cout << rCnt;
	return 0;
}
