#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 虽然负权边的题几乎没怎么做过也没怎么见到过，不过刷最短路专题的时候感觉还是有必要的，那么考虑到判断负环的算法
// 只有SPFA和Bellman，而SPAF代码上类似Dijkstra，所以这里就用SPFA来做这类题好了，不过据说SPFA会被卡，指的就是其
// 时间复杂度最坏会变成O(nm)，但是Bellman算法的复杂度就是O(nm)所以可能就算被卡也只是和Bellman算法一样慢罢w... 

// SPFA的算法思想就是对一个点进行多次松弛，即利用一个循环队列和一个标记数组来进行不断松弛，运行过程大概是先将队头
// 的元素出队，然后标记为未访问，下面就进行类似Dijkstra算的松弛过程，即枚举所有边，然后判断这个边的距离到现在这个点
// 的距离是否可以更短，如果更短，将其标记为true，然后入队。可以看出来SPFA除了两次标记和多次入队外，几乎和Dijkstra没
// 有太大的区别。这里主要介绍两次标记，首先，来看第二次标记，这里SPFA直接对入队的点标记为true了，这就意味着这个点在
// 一次松弛过程中不会被重复使用，注意是一次松弛过程。然后是第二个标记，这个标记是为了保证一个点多次入队，如果当前这个
// 点的边的距离已经松弛完毕了，那么它的这条边所连接的那个点就不会再次入队，即不会被标记为false...感觉完全在瞎扯，果然
// 还是上代码好了w... 

// 有向图 
const int N = 1e5 + 10;
int head[N], e[N], ex[N], w[N], idx = 0;
int dist[N];
bool visited[N];
queue<int > que;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int spfa(int st, int n) {
	memset(dist, 0x3f, sizeof dist);
	// visited[st] = 1;
	dist[st] = 0;
	// 注意SPFA入队的不是pair，因为它不用像Dijkstra那样根据边权排序... 
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 松弛操作，因为不用按边权排序，所以直接用原数组取值就行 
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				// 防止重复访问... 
				if (!visited[vt]) {
					visited[vt] = 1;
					que.push(vt); 
				}
			}
		}
	} 
	return dist[n];
}
int main() {
	memset(head, -1, sizeof head);
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	int res = spfa(1, n);
	// 如果存在负权边，则不存在最短路 
	if (res == 0x3f3f3f3f) printf("impossible");
	else printf("%d", res);
	puts("");
	return 0;
}
