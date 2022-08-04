#include <iostream>
using namespace std;

// 分三种情况讨论：
// 1. 什么时候加一：当农夫的坐标x还在N之内就可以执行加一操作
// 2. 什么时候减一：只要当农夫的坐标x>0就能进行减一操作
// 3. 什么时候乘二：只要当农夫的坐标x*2<N就可以执行乘二操作

// 什么时候退出BFS
// 当农夫坐标x等于牛的坐标时即可

// 如何计算步数：用一个dist数组存放每次操作操作的步数，当前步数就等于上次步数加一 

// 开两倍是为了防止乘二操作越界 
const int N = 2e5 + 10;
int n, k;
int que[N], dist[N];
int bfs() {
	int qtop = 0, qback = 0;
	// 自己到自己的距离为0 
	fill(dist, dist + N, -1);
	dist[n] = 0;
	// 从当前点开始扩展 
	que[0] = n;
	while (qtop <= qback) {
		int t = que[qtop++];
		// 如果找到了答案，直接返回距离 
		if (t == k) return dist[t];
		// 用dist数组存放距离同时判断某个节点是否访问过 
		if (t + 1 < N && dist[t + 1] == -1) {
			// 当前节点的距离就是上个节点的距离+1 
			dist[t + 1] = dist[t] + 1;
			// 下次从这个点开始扩展 
			que[++qback] = t + 1;
		}
		if (t - 1 >= 0 && dist[t - 1] == -1) {
			dist[t - 1] = dist[t] + 1;
			que[++qback] = t - 1;
		} 
		if (t * 2 < N && dist[t * 2] == -1) {
			dist[t * 2] = dist[t] + 1;
			que[++qback] = t * 2;
		}
	}
	return 0;
}
int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
} 
