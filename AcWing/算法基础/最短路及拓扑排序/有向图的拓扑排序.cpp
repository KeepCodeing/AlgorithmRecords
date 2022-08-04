#include <iostream>
#include <queue>
using namespace std;

// 拓扑序列的概念：对于一个有向无环图，一定存在一个序列满足类似1 -> 2 -> 3 , 2 -> 3, 1 -> 3的关系，
// 即作为起点的点永远都在作为重点的点的前面。

// 拓扑排序的步骤：我们知道入度为0的点一定是起点，所以可以先从入度为0
// 的点开始BFS 

// 注意：无向图没有拓扑序列，存在环的有向图也没有拓扑序列，拓扑序列一般用BFS实现。
// 另外，有向无环图又称为拓扑图

// 如何判断一个有向图是否有环： 无环的有向图一定存在一个入度为0的点 

const int N = 10010, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
// indg记录某个点的入度，topu记录答案 
int indg[N], topu[N];
int n, m;
void add(int k, int val) {
	e[idx] = val, ex[idx] = head[k], head[k] = idx++;
}
bool topusort() {
	// 统计入度为0的点有几个
	queue<int > que;
	int cnt = 0;
	// 一共有n个顶点 
	for (int i = 1; i <= n; i++) {
		if (!indg[i]) {
			// 从入度为0（即起点）的顶点开始BFS 
			que.push(i);
			// 如果是起点，那么绝对是排在最前面的 
			topu[++cnt] = i; 
		}
	} 
	while (!que.empty()) {
		// 优先从入度为0的点开始遍历， 并且访问所有这条边能到的顶点 
		int u = que.front();que.pop();
		for (int i = head[u]; i != -1; i = ex[i]) {
			int j = e[i];
			// 当前顶点入度自减，如果这个顶点的入度减成0了，就说明它前面的点已经排序完了，那么
			// 接下来就可以从这个点开始排序了 
			indg[j]--;
			if (!indg[j]) {
				// 将点j也添加到队中 
				que.push(j);
				// 记录答案，入度先为0的点排的更前 
				topu[++cnt] = j; 
			}
		}
	}	
	// 如果所有点都能排序，就说明这个图没有环，即可以得到答案 
	if (cnt == n) return true;
	// 否则就说明这个图有环，不能得到答案 
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N + 10, -1);
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		// 记录点v的入度 
		indg[v]++;
		add(u, v);
	}
	if (topusort()) {
		for (int i = 1; i <= n; i++) cout << topu[i] << ' ';
	} else {
		cout << -1;
	}
	return 0;
} 

/*
输入样例：
3 3
1 2
2 3
1 3

输出样例：
1 2 3
*/
