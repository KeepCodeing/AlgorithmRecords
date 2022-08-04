#include <iostream>
#include <cstring>
using namespace std;

// 总体上有点类似Dijkstra求最短路，不过这里运用的是贪心思想，每次
// 选择都选择代价最小的点，Prim算法主要是用顶点求最小花费 

// Prim算法流程概述：这个算法和Dijkstra算法几乎差不多，只不过更新的是消费
// 首先，同样是找到一个最近点，同时记录这个点的代价，然后利用这个点，去
// 去代价数组里找是否有代价大于这个点到其任意连通点，如果有，更新 

#define N 6
#define INF 114514
int dist[N];
bool visited[N];
int graph[N][N] = { {INF,7,4,INF,INF,INF},   //INF代表两点之间不可达
                    {7,INF,6,2,INF,4}, 
                    {4,6,INF,INF,9,8}, 
                    {INF,2,INF,INF,INF,7}, 
                    {INF,INF,9,INF,INF,1}, 
                    {INF,4,8,7,1,INF}
                  };

int prim(int cur) {
	int index, sumMoney = 0;
	memset(visited, false, sizeof(visited));
	cout << cur << ' ';
	visited[cur] = true;
	for (int i = 0; i < N; i++) {
		// 初始化当前点可以到达的点的距离 
		dist[i] = graph[cur][i];
	}
	for (int i = 1; i < N; i++) {
		int minMoney = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[j] < minMoney) {
				// 找到离当前点最近的点，并更新最小代价以及这个点的下标 
				index = j;
				minMoney = dist[j];
			}
		}
		// 使用这个点 
		visited[index] = true;
		cout << index << ' ';
		sumMoney += minMoney;
		// 从当前点能到的最近点开始扩展，也就是换个点开始遍历 
		for (int j = 0; j < N; j++) {
			// 将起始点到j点的非最小花费的点更新为当前最近点的花费 
			if (!visited[j] && dist[j] > graph[index][j]) {
				dist[j] = graph[index][j];
			}
		}
	}
	cout << endl;
	return sumMoney;
}

int main() {
	cout << prim(0) << endl;
	return 0;
}
