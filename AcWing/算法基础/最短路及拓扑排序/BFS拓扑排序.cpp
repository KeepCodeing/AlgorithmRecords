#include <iostream>
#include <cstdio>
using namespace std;

// 一个图有拓扑序的前提：这个图是有向图，且没有环

// 拓扑序的思路就对整个图进行一次BFS，每次从入度为0的点开始，如果某个点入度为0了，那就说明它已经被排序完成了（只能
// 作为起点，类似一个链表），最后判断下是不是所有点都入队了（不能说所有点入度都为0，因为最后一个点入度必然不为0），
// 如果所有点都入队了，那么队列里的元素就是这个图的拓扑序，否则就说明这个图存在环路。 
// 另外要注意，一个图的拓扑序不是唯一的 

// 注意为什么队列要么是只有n - 1要么不是，因为将一个入度为0的点入队后就相当于删去了其所有入边，也就是这个点
// 无法再到达，后面也是同理，删一个点就会少很多边.. 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m; 
int rd[N];
int que[N];
bool topsort() {
	int qtop = 0, qback = -1;
	// 将所有入度为0的点放入队列，从这些点开始扩展 
	for (int i = 1; i <= n; i++) 
		if (!rd[i]) que[++qback] = i;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			rd[vt]--;
			// 如果当前点入度也为0，则说明当前点已经排序完成，可以从这个点扩展 
			if (!rd[vt]) que[++qback] = vt;
		}
	}
	// 如果最后所有点都入队了，就说明这个图没有环，否则就必定存在环 
	return qback == n - 1;
}
int main() {
	fill(head, head + N, -1);
	int ut, vt;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt);
		// 统计入度 
		rd[vt]++;
	}
	if (topsort()) {
		// 如果该图存在拓扑序，队列里的元素顺序就是拓扑序之一，注意这里队列的下标是从0开始的 
		for (int i = 0; i < n; i++) printf("%d\n", que[i]);
	}
	return 0;
}
