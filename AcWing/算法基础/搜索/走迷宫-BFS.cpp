#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
};
const int N = 110;
int n, m;
bool graph[N][N];
queue<Node > que;
int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs() {
	Node now;
	que.push((Node){1, 1, 0});
	while (!que.empty()) {
		now = que.front();que.pop();
		// 判断当前点是不是到了终点，而不是判断下一个点到没到终点 
		if (now.x == n && now.y == m) {
			cout << now.step;
			return;
		} 
		for (int i = 0; i < 4; i++) {
			// 改用一个全新的结构体存状态，这也就是为什么BFS占用内存大
			// 的原因 
			Node nx(now.x + move[i][0], now.y + move[i][1], now.step + 1);
			if (nx.x < 1 || nx.x > n || nx.y < 1 || nx.y > m) continue;
			if (graph[nx.x][nx.y]) continue;
			graph[nx.x][nx.y] = true;
			que.push(nx); 
		}
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	bfs();
	return 0;
}

// 老毛病，没有记录步数，用一个变量走到底... 

//const int N = 110;
//bool graph[N][N];
//int n, m;
//queue<pair<int, int > > que;
//int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//int bfs() {
//	int cnt = 0;
//	pair<int, int > now, nx;
//	que.push(pair<int, int >(1, 1)); 
//	while (!que.empty()) {
//		now = que.front();que.pop();
//		for (int i = 0; i < 4; i++) {
//			nx.first = now.first + move[i][0], nx.second = now.second + move[i][1];
//			if (nx.first < 1 || nx.first > n || nx.second < 1 || nx.second > m) continue;
//			if (graph[nx.first][nx.second]) continue;
//			cnt++;
//			if (nx.first == n && nx.second == m) return cnt;
//			graph[nx.first][nx.second] = true;
//			que.push(nx); 
//		}
//	}
//	return cnt;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> graph[i][j];
//		}
//	} 
//	cout << bfs();
//	return 0;
//}
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

8
*/
