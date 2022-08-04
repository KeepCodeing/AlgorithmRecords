#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 好像SPFA算法比较玄学，不一定能通过所有测试，所有还是用稳定的Dijkstra算法罢了 
const int INF = 99999;
int n, m, s;
int *dist;
bool *visited;
struct Node {
	// 当前顶点能到的点及其权重 
	int v, weight;
	Node(int v, int w) : v(v), weight(w) {}
};
vector<Node > graph[10010];
// 测试邻接表存储 
// 邻接表的好处：不用存放无法访问的节点，空间更大，有时如果数据范围到了10^5，用邻接矩阵
// 绝对会MLE的 
void dfs(int cur) {
	visited[cur] = true;
	cout << cur << ' ';
	for (int i = 0; i < graph[cur].size(); i++) {
		// graph[cur]表示访问cur这个顶点的所有连通顶点 
		if (!visited[graph[cur][i].v]) {
			// graph[cur][i].v就是把每个顶点的顶点值取出来 
			visited[graph[cur][i].v] = true;
			dfs(graph[cur][i].v);
		}
	}
}
void dijkstra(int cur) {
	dist[cur] = 0;
	int index, minDist;
	// 这里应该是从起点开始，将距离初始化为各个连通顶点的权重 
	for (int i = 0; i < graph[cur].size(); i++) dist[graph[cur][i].v] = graph[cur][i].weight;
	// for (int i = 0; i < graph[cur].size(); i++) cout << graph[cur][i].weight << ' ';
	// 忘了的点1：将起点标记 
	visited[cur] = true;
	// 这里不是遍历起点的连通顶点，而是对全部顶点进行遍历 
	for (int i = 1; i <= n - 1; i++) {
		minDist = INF;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				minDist = min(dist[j], minDist);
				index = j;
			}
		}
		visited[index] = true;
		for (int v = 0; v < graph[index].size(); v++) {
			// 多余的点1：修正路径时不用判断是否使用过某个顶点 
			// if (!visited[graph[index][v].v]) {

				// 忘记的点2:是对dist数组的每个元素进行更新，而不是对当前最近的那个
				// 元素更新 
				
				// 如果index（最近顶点）到v有通路 
				if (graph[index][v].weight != INF) {
					if (dist[graph[index][v].v] > dist[index] + graph[index][v].weight) {
						dist[graph[index][v].v] = dist[index] + graph[index][v].weight;
					}
					
				}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	// 坑：memset不能用来初始化整形数组，即是是初始化，也只能初始化为0 
	// memset(dist, INF, sizeof(dist));
	// cout << dist[1] << endl;
	visited = new bool[n + 1];
	dist = new int[n + 1];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		// 表示顶点u到顶点v有边，且长度为w
		// 注意初始是(Node){}，否则可能会有个warning  
		graph[u].push_back((Node){v, w});
	} 
	dijkstra(s);
	// dfs(s);
	for (int i = 1; i <= n; i++) {
		cout << dist[i];
		if (i != n) cout << ' ';
	}
	delete[] visited, dist;
	return 0;
}
