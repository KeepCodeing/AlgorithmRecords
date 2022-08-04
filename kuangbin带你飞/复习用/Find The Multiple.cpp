#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ULL;
bool flag = false;
void dfs(int n, ULL ans, int deepth) {
	// 池沼了不记得怎么加剪枝了...应该是在进入递归前就剪枝，而不是进入完了才标记.. 
	if (deepth >= 19 || flag) return;
	if (ans % n == 0) {
		if (!flag) cout << ans << endl, flag = true;
		return;
	}
	dfs(n, ans * 10 + 1, deepth + 1);
	dfs(n, ans * 10, deepth + 1);
}
int main() {
	int n;
	while (scanf("%d", &n), n) {
		flag = false;
		dfs(n, 1, 0);
	}
	return 0;
}
