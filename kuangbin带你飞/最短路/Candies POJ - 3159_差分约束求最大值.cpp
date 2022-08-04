#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

// 这个值是个典型的差分约束求最大值，题目要求B最多能比A多拿多少颗糖，那么设B最多能多拿C颗糖，于是就有
// B-A<=C，这个不等式应该有很多个，即一个不等式组，那么这个其实就是松弛条件了。我们将这些个不等式建立
// 成一个单向图，然后对上面的式子移项有B <= A + C，A就是当前点，B就是A的一条边能到的点，那么C就是这条
// 边的权重。根据我们之前的结论可以知道，如果要求最大值，那就跑最短路，否则就跑最长路，而 <= 的形式就是
// 最短路的形式，也就是说我们在写式子的时候就根据其符号判断松弛条件，最长路就是 >= （这里说的有问题，应该
// 只根据不等式来，可能最短路就是B <= A + C，最长路就是 A <= B + c之类的...）...(，然后注意不管是最长路
// 还是最短路，我们都只要有一个路径满足就行了，也就是不等式在代码里的体现是不带=的... 似乎有问题，有待商榷） 
// 然后注意转换成最短路问题后，就用Dijkstra跑就行了，SPFA很可能被卡，这个题SPFA得用栈才能过... 

/*
感觉有点蒙，主要是为什么松弛的不等式和列出来的不等式相反...似乎求最短路的B <= A + C在松弛里就变成了B > A + C，
而最长路的B >= A + C在松弛里变成了B < A + C，这个解释起来好像挺麻烦的，其也搞不懂...总之当成公理用应该就没事了..

一句博客里的话，简洁明了...感觉差分约束对其还有一定难度，得稍稍了w... 
差分约束系统有两种方式可以求解，最短路和最长路。当我们把不等式整理成d[a]+w<=d[b]时，我们求最长路。整理成d[a]+w>=d[b]时，
我们求最短路。 
*/

typedef pair<int, int > PII;
const int N = 30000 + 10, M = 150000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
int n, m;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 松弛条件，似乎和上面说的矛盾了，总之其自己的想法是 A + C <= B，那就和这里是一样的了...不过好像不是这样
			// 似乎是因为差分约束的特性，大于小于号要和式子反着来... 
			if (wt + w[i] < dist[vt]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[n];
}
int main() {
	memset(head, -1, sizeof head);
	int ut, vt, wt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// 加条单向边，u就是A，v就是B，w就是C 
		add(ut, vt, wt);
	}
	printf("%d", dijkstra(1));
	return 0;
}
