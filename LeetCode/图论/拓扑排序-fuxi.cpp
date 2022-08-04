#include <iostream>
#include <cstring>
using namespace std;

// 较为简单的拓扑排序倒是没忘记，不过值得注意的是如何判断一个图是否能组成拓扑图，
// 当n-1个点的入度都为0时，这个图才能算拓扑图，至于为是么是n-1个点，因为最后一个点
// 入度一定为1，而其它所有点出度一定为1 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int rd[N];
int que[N];
// 注意这里入队的坑，qback的初值一定要从-1开始，然后遵循左自增的规则，
// 其一开始写的是初值为0，右自增，不知道为什么出错了...以前的类似多源
// 最短路BFS倒是这样这样写... 
int qtop = 0, qback = -1;
bool topsort(int n) {
	for (int i = 1; i <= n; i++)
		if (!rd[i]) que[++qback] = i;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			rd[vt]--;
			if (!rd[vt]) que[++qback] = vt;
		}
	}
	return qback == n - 1;
}
int main() {
	int n, m, ut, vt;
	memset(head, -1, sizeof head);
	cin >> n >> m;
	while (m--) {
		cin >> ut >> vt;
		add(ut, vt);
		rd[vt]++;
	}
	if (topsort(n)) 
		for (int i = 0; i < n; i++) cout << que[i] << ' ';
	return 0;
}
/*
3 3
1 2
2 3
1 3
*/
