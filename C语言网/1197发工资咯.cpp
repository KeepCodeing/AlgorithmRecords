#include <iostream>
using namespace std;

// 经典贪心题目，贪心策略是优先选更大的钱 

int money[] = {100, 50, 10, 5, 2, 1};
int getCnt(int m) {
	int index = 0;
	int cnt = 0;
	while (m) {
		if (m - money[index] >= 0) m -= money[index], cnt++;
		else index++;
	}
	return cnt;
}
int main() {
	int n;
	int cnt;
	int human;
	while (cin >> n) {
		if (!n) break;
		cnt = 0;
		for (int i = 0; i < n; i++) cin >> human, cnt += getCnt(human);
		cout << cnt << endl;
	}
	return 0;
}
