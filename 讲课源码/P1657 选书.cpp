#include <iostream>
using namespace std;

const int N = 30;
int book[N][3];
bool used[N];
int ans = 0;

void dfs(int n) {
	if (n <= 0) {
		ans++;
		return;
	}

	for (int k = 1; k <= 2; k++) {
		if (!used[book[n][k]]) {
			used[book[n][k]] = true;
			dfs(n - 1);
			used[book[n][k]] = false;
		}
	}

//	if (!used[book[n][1]]) {
//		used[book[n][1]] = true;
//		dfs(n - 1);
//		used[book[n][1]] = false;
//	}
//
//	if (!used[book[n][2]]) {
//		used[book[n][2]] = true;
//		dfs(n - 1);
//		used[book[n][2]] = false;
//	if (!book[n][2]) dfs(n - 1, 2);
}

int main() {
	int x;
	cin >> x;
	if (x <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= x; i++) cin >> book[i][1] >> book[i][2];
	dfs(x);
	cout << ans << endl;
	return 0;
}
