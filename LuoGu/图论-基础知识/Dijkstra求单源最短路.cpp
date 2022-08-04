#include <iostream>
using namespace std;

// 单源最短路就是指一个节点到其它节点的最小值 
// Dijkstra是稳定单源最短路算法 

int graph[1000][1000], dis[1000], visited[1000];
int n, m;
// 注意，这里之前偷懒用-1代替了inf，但是这样做似乎有些问题 
int inf = 114514;

// Dijkstra算法流程概述：每次都在距离数组中查询最近的节点，然后利用这个最小值去更新
// 距离数组，更新即是判断距离数组中是否有距离比当前最短距离节点到其连通的任意节点更距离更长
// 如果更长就更新值 

void Dijkstra() {
	// 初始化dis数组，用来存放某个节点到其它所有节点的最短距离
	// 这里把dis数组初始化为了节点1到其它所有节点的距离 
	for (int i = 1; i <= n; i++) dis[i] = graph[1][i];
	// 初始化visited数组 
	for (int i = 1; i <= n; i++) visited[i] = 0;
	// 从1点开始松弛 
	visited[1] = 1;
	// Dijkstra算法核心语句
	int minDis, u;
	for (int i = 1; i <= n - 1; i++) {
		// 当前能找到的最短路径 
		minDis = inf;
		// 找到离1号顶点最近的节点
		for (int j = 1; j <= n; j++) {
			// 这里可以用priority_queue进行优化，要用小顶堆 
			if (!visited[j] && dis[j] < minDis) {
				minDis = dis[j];
				// 记录最短距离节点的下标 
				u = j;
			}
		}
		// 将目前找到的最短路径设置为以访问 
		visited[u] = 1;
		// 修正当前最短路径 
		for (int v = 1; v <= n; v++) {
			// 遍历所有点，并判断所有最短点到其它合法点的距离是否能更短 
			if (graph[u][v] < inf) {
				// 从当前最短距离点进行松弛操作，即将u到v的最短距离进行对比 
				if (dis[v] > dis[u] + graph[u][v]) dis[v] = dis[u] + graph[u][v];
			}
		} 
	} 
}

int main() {
	
	cin >> n >> m;
	// 初始化图 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = inf;
			else graph[i][j] = 0;
		}
	}
	int x, y, w;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
	Dijkstra();
	// 输出结果 
	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
 	return 0;
}
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
