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
int f[10010];
int main() {
	int n, m;
	cin >> n >> m;
	cai = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> cai[i];
	}
	// dfs(1, n, m);
	// 这个题和普通01背包唯一的区别就是他不是求最值，而是求
	// 方案数
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= cai[i]; j--) {
			// 现在的花费种类+=我不点这个菜的时候的花费种类或者我点（二者相同） 
			f[j] += f[j - cai[i]];
		}
	} 
	cout << f[m];
	delete[] cai;
	return 0;
}
