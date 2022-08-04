#include <iostream>
#include <queue>
using namespace std;
const int N = 100010, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
struct Node {
	int x, step;
	
	Node (int x, int step) : x(x), step(step) {};
	Node () {};
};
bool visited[N];
int n, m;
void add(int k, int val) {
	e[idx] = val, ex[idx] = head[k], head[k] = idx++;
}
void bfs() {
	queue<Node > que;
	que.push((Node){1, 0});
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.x == n) {
			cout << now.step;
			return;
		}
		for (int i = head[now.x]; i != -1; i = ex[i]) {
			int j = e[i];
			if (!visited[j]) {
				visited[j] = true;
				que.push((Node){j, now.step + 1}); 
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N, -1);
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		add(u, v);
	} 
	bfs();
	return 0;
}
