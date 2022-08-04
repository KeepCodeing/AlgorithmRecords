#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int n) {
	if (n < 0) return;
	if (!n) {
		cnt++;
		return;
	}
	dfs(n - 1);
	dfs(n - 2);
}
int main() {
	int n;
	cin >> n;
	dfs(n);
	cout << cnt;
	return 0;
}
