#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f

// 这个算法就是Bellman-Ford的队列优化版本，效率更高，有点类似与广搜，区别是其可以不断
// 入队一个元素，另外存在负权边的图其实没有最短路径 
// SPFA不一定能稳定求出最短路径，因为其不断对一个点入队可能导致复杂度飙升，不过一般
// 不会出现这种情况 

struct node {
	int y, z;
	// 注意初始化方式，这样初始化似乎在(node){y, z}的时候起到了作用 
	node(int a, int b) : y(a), z(b){};
	// 这样初始化导致y，z都是0 
//	node(int a = 0, int b = 0) {
//		y = a, b = z;
//	}
};
// 图的大小，以及边数 
int n, m;
// 用邻接表存图，适用于m<n^2的情况 
vector<node > graph[1000];
// 队列 
queue<int > que;
// 用来存放结果的数组以及标记访问的数组 还有记录
// 入队次数的数组，因为有负权边的图spfa遍历不能 
int dist[1000], visited[1000], enter_cnt[1000];

void spfa(int cur) {
	// 初始化visited数组和enter_cnt数组 
	// for (int i = 1; i <= n; i++) visited[i] = enter_cnt[i] = 0;
	// 自己到自己的距离为0 
	dist[cur] = 0;
	// 入队，和BFS类似 
	que.push(cur);
	// 标记以访问 
	visited[cur] = 1; 
	// cur元素入队次数自增
	enter_cnt[cur]++;
	
	int x;
	while(!que.empty()) {
		x = que.front();
		que.pop();
		// 对所有边进行遍历 
		for (int i = 0; i < graph[x].size(); i++) {
			// 进行松弛，当当前距离加上该边上任意一个元素的权值比该边直接到另一个边的
			// 权值小时就进行松弛，如果所有边都松弛完了，程序就结束了 
			if (dist[x] + graph[x][i].z < dist[graph[x][i].y]) {
				dist[graph[x][i].y] = dist[x] + graph[x][i].z;
				// 如果未访问过，对当前边上所有可以到达的点进行入队松弛 
				if (!visited[graph[x][i].y]) {
					que.push(graph[x][i].y);
					enter_cnt[graph[x][i].y]++;
					// 如果不存在负权边，则每个节点都不可能被遍历n次以上，
					// 如果出现了负权边，spfa无法处理，直接返回 
					if (enter_cnt[graph[x][i].y] >= n) {
						cout << "ERROR!" << endl;
						return;
					}
					// 标记访问过 
					visited[graph[x][i].y] = 1;
				}
			}
		}
	} 
} 
/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
0 -3 -1 2 4

5 7
1 2 3
1 3 2
2 4 1
4 1 4
4 3 6
4 5 4
5 3 4
0 3 2 4 8
*/

int main() {
	int x, y, z;
	cin >> n >> m;
	// 初始化结果数组，虽然全局变量默认为0
	for (int i = 1; i <= n; i++) dist[i] = inf;
	for (int i = 1; i <= m; i++) {
		// x->y,z是权值 
		cin >> x >> y >> z;
		// 存入有向图 
		graph[x].push_back((node){y, z}); 
		// 要存入无向图加一个{z,y}即可 
	}
	// 调用 
	spfa(1); 
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	return 0;
} 
