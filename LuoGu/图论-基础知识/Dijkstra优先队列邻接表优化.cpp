#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 优化的部分就是每次去dist数组里找最近顶点那块，用for找复杂度为O(n)，
// 用优先队列找复杂度为O(logn) 

struct node {
	int v, weight;
	node(int v, int weight) : v(v), weight(weight) {};
//	node(int v1, int w1) {
//		v = v1, weight = w1;
//	}
	bool operator<(const node& n) const {
		// 提供优先队列排序规则，顶点小更靠前，权值大更靠前 
		if (v != n.v) return v < n.v;
		return weight > n.weight;
	}
	
};
int n, m, s;
const int INF = 0x3F3F3F3F;
vector<node > graph[10010];
bool *visited;
int *dist;
priority_queue<node > que; 

void dijkstra(int start) {
	// 从起点开始松弛边 
	dist[start] = 0;
	que.push((node){start, dist[start]}); 
	// 注意这里的初始化，不然没办法用node 
	node x(0, 0), y(0, 0);
	while (!que.empty()) {
		// 取出节点标号最小或者权值最高的顶点 
		x = que.top();que.pop();
		// 遍历这个顶点所有的连通边 
		for (int i = 0; i < graph[x.v].size(); i++) {
			// 取出该顶点的连通顶点 
			y = graph[x.v][i];
			// 开始松弛，即判定起点到目前这个点的距离是否大于起点的最近点的权值+这个点的权值
			// 如果大于，更新更小的距离值，然后将这个点放入队列 
			if (dist[y.v] > dist[x.v] + y.weight) {
				dist[y.v] = dist[x.v] + y.weight;
				que.push((node){y.v, dist[y.v]});
			}
		}
	}
}
// memset不能对整形数组初始化为0或者-1之外的值，因为它是按字节来初始化的 
void initArray(int n) {
	// for (int i = 1; i <= n; i++) visited[i] = false, dist[i] = INF;
	// fill可以对任意类型的数组初始化，fill(指针, 初始化大小， 值) 
	visited = new bool[n + 1];
	dist = new int[n + 1];
	fill(visited, visited + n, false);
	fill(dist, dist + n, INF);
}
int main() {
	// 图大小，边数，起点
	cin >> n >> m >> s;
	// 初始化数组 
	initArray(n);
	// <u,v>，权值 
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back((node){v, w});
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) cout << dist[i] << (i != n ? " " : "");
	delete[] visited, dist;
	return 0;
}
