#include <iostream>
#include <queue>
using namespace std;

// 和之前写的vector版有点不一样，首先是没有用结构体了，
// 其次priority_queue的排序方式也变成了权值优先，还有就是
// 循环变了个样子，总体长得像BFS了 

const int N = 100010, INF = 0x3FFFFFFF;
// 新加了个w数组用来存权重 
int head[N], e[N], ex[N], w[N], idx = 0;
void add(int k, int val, int wei) {
	e[idx] = val, w[idx] = wei, ex[idx] = head[k], head[k] = idx++;
}
// 新增一个pair用来存顶点的权值和这个顶点
typedef pair<int, int > PII; 
// 新增了一个访问标记数组，虽然之前加不加都可以 
bool visited[N];
int dist[N];
int n, m;
int dijkstra() {
	dist[1] = 0;
	// 升序队列 
	priority_queue<PII, vector<PII >, greater<PII > > que; 
	// 权值大的顶点优先，这里的意思是从顶点1开始，这个1到1的距离为0 
	que.push(PII(0, 1));  
	while (!que.empty()) {
		PII t = que.top();que.pop();
		// 取出顶点编号和权值 
		int v = t.second, distance = t.first;
		if (visited[v]) continue;
		// 将未访问过的点标记 
		visited[v] = true;
		// 遍历这个点的所有边 
		for (int i = head[v]; i != -1; i = ex[i]) {
			int j = e[i];
			// 对比从当前直接到j点近还是通过v点到j点近 
			if (dist[j] > w[i] + distance) {
				dist[j] = w[i] + distance;
				// visited[i] = true;
				que.push(PII(dist[j], j)); 
			}
		} 
	}
	if (dist[n] == 0x3FFFFFFF) return -1;
	return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N, -1);
	fill(dist, dist + N, INF);
	cin >> n >> m; 
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	cout << dijkstra();
	return 0;
}

/*

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/
