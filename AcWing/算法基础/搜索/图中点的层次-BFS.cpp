#include <iostream>
#include <queue>
using namespace std;

// 边权不存在（为1），所以可以用BFS求最短路 

// 草草草，第一次答案对了完完全全是运气好，核心代码完全错乱 
// 主要是没有标记访问过，扩展的点写成了边的编号，还有就是忘了
// 初始化头结点 

const int N = 100010, M = N * 2;
struct Node {
	int u, step;
	Node () {};
	Node (int u, int step) : u(u), step(step) {};
};
int head[N], e[M], ex[M], idx = 0;
// 标记某个顶点是否被访问过（之前居然没加这个） 
bool visited[N];
int n, m; 
queue<Node > que;
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = head[k];
	head[k] = idx;
	idx++;
}
void bfs() {
	que.push((Node){1, 0});
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.u == n) {
			cout << now.step;
			return;
		}
		// 稍稍理解了点这种建图方式，其实和vector邻接表是一样的
		// 不一样的地方就是用数组模拟我们不知道某个顶点到底有多少条
		// 边，只能通过-1这个标记来说明没有边，也就是说这里ex[i]其实是
		// 存的当前顶点的边指向的那个顶点的编号，之前居然理解成了是指向的
		// 顶点的值.... 
		for (int i = head[now.u]; i != -1; i = ex[i]) {
			// 把这条边能到的顶点取出来 
			int j = e[i];
			// 判断下这个点是否被访问过 
			if (!visited[j]) {
				// 标记这个点被访问了 
				visited[j] = true;
				// 从这个点开始继续扩展 
				que.push((Node){j, now.step + 1});
			}
		}
		/*
		可以对比下vector邻接表的形式，这里写的是Dijkstra求最短路的模型 
		que.push((Node){...});
		Node x = que.top();que.pop;
		for (int i = 0; i < graph[x.u].size(); i++) {...}
		*/ 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 千万不要忘了初始化头结点的值，不然遍历的时候没办法
	// 停下来 
	fill(head, head + N + 10, -1);
	cin >> n >> m;
	int u, v; 
	while (m--) { 
		cin >> u >> v;
		// 有向图 
		add(u, v);
	} 
	bfs();
	return 0;
}
/*
输入样例
4 5
1 2
2 3
3 4
1 3
1 4

2 4

输出样例
1
*/
