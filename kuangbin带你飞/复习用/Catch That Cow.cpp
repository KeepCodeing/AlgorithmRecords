#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 10, M = N * 2;
int dist[M];
int que[M];
int bfs(int st, int ed) {
	memset(dist, -1, sizeof dist);
	int qtop = 0, qback = 0;
	dist[st] = 0;
	que[qtop] = st;
	while (qtop <= qback) {
		int now = que[qtop++];
		if (now == ed) return dist[now];
		if (now + 1 < N && dist[now] == -1) {
			que[++qback] = now + 1;
			dist[now + 1] = dist[now] + 1;
		}
		if (now - 1 >= 0 && dist[now - 1] == -1) {
			que[++qback] = now - 1;
			dist[now - 1] = dist[now] + 1;
		}
		if (now * 2 < M && dist[now * 2] == -1) {
			que[++qback] = now * 2;
			dist[now * 2] = dist[now] + 1;
		}
	}
	return -1;
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
