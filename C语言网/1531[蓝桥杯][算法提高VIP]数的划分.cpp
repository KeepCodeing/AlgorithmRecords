#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int level, int deepth, int num) {
	if (num == 0) {
		cout << level << endl;
		cnt++;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		if (num - i < 0) continue;
		dfs(i, deepth, num - i);
	}
}
// 1 2 3 5 7 11 15 22
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		dfs(1, i, i);
		cout << i << '=' << cnt << endl;
	}
	
	return 0;
}
