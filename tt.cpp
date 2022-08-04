#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
const int INF = 999999;
int arr[N];
int num = 0, n = 0;
int res = 999999;

void dfs(int level, int money, int cnt) {
	if (money < 0) return;
	if (level >= n || money == 0) {
		res = min(res, cnt);
//		cout << "aaaaaaaaa" << endl;
		return;
	}
	for (int i = level; i < n; i++) {
//		cout << arr[i] << ' ' << i << endl;
		dfs(i, money - arr[i], cnt + 1);
	}
}

int main() {
	while (cin >> num && num) {
        res = INF;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		dfs(0, num, 0);
		if (res != INF) cout << res << endl;
        else cout << "Impossible" << endl;
	}
}
