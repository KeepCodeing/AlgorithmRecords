#include <iostream>
using namespace std;

// 这就是个普通01背包题，不过其太池沼没看出来，先用回溯写下 
// 看起来数据比较水，因为N<=100都过了，接下来再用动规写下
 
int *cai;
int cnt = 0;
void dfs(int level, int deepth, int target) {
	if (target <= 0 || level == deepth + 1) {
		if (target == 0) cnt++;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		// 剪枝，不知道会不会TLE 
		if (cai[i] > target) continue;
		dfs(i + 1, deepth, target - cai[i]);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	cai = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> cai[i];
	}
	dfs(1, n, m);
	cout << cnt;
	delete[] cai;
	return 0;
}
