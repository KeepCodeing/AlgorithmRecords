#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// BFS枚举状态 
// 一瞬写完，做了那几个要枚举状态的BFS之后算是理解了这种题怎么写了，
// 之前有背代码之嫌，因为那时候甚至不知道枚举的是状态... 

const int N = 100000 * 2 + 10;
// 因为不知道有多少种状态所以用个queue来当队列 
queue<int > que;
int dist[N];
int bfs(int n, int k) {
	memset(dist, -1, sizeof dist);
	dist[n] = 0;
	que.push(n);
	while (que.size()) {
		int now = que.front();que.pop();
		if (now == k) return dist[now];
		if (now + 1 < N && dist[now + 1] == -1) {
			dist[now + 1] = dist[now] + 1;
			que.push(now + 1);
		}
		if (now - 1 >= 0 && dist[now - 1] == -1) {
			dist[now - 1] = dist[now] + 1;
			que.push(now - 1);
		}
		if (now * 2 < N && dist[now * 2] == -1) {
			dist[now * 2] = dist[now] + 1;
			que.push(now * 2);
		}
	}
	return 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
