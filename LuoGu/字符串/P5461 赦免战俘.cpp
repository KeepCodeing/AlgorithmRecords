#include <iostream>
using namespace std;
void dfs(int l, int r) {
	if (l == 0 && r == 0) return;
	cout << l << ' ' << r << endl;
	dfs(l / 2, r / 2);
	dfs(l / 2, r / 2);
	dfs(l / 2, r / 2);
	dfs(l / 2, r / 2);
}
int main() {
	int n, sz = 1;
	cin >> n;
	for (int i = 0; i < n; i++) sz *= 2;
	sz *= sz;
	dfs(sz, sz);
	return 0;
}
