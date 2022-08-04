#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

// 事01背包问题，但是不是简单的求所有方案数，而且加了个能够被整除的约束
// 暂且不知道怎么写，不过应该可以搞个记忆化搜索 

// 大爆搜得了60分..，其余点全TLE了，虽然想写记忆化但是发现第二个状态太大了，数组开不下... 

const int N = 2010, M = 100010;
int cow[N];
int n, m;
int cnt = 0;
int f[N][N];
int dfs(int level, int deepth, int sumNum) {
	if (level == deepth) {
		if (!(sumNum % m) && sumNum != 0) cnt++;
		return 1;
	}
	if (f[level][sumNum] != -1) return f[level][sumNum];
	f[level][sumNum] = dfs(level + 1, deepth, sumNum + cow[level]);
	f[level][sumNum] = dfs(level + 1, deepth, sumNum);
}

int main() {
	cin >> n >> m;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; i++) cin >> cow[i];
	sort(cow + 1, cow + n);
	dfs(1, n + 1, 0);
	cout << cnt;
	return 0;
}
