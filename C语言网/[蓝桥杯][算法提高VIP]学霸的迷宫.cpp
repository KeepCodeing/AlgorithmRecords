#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 翻到了以前的naive代码...方向做个对比好了，证明自己确实有在进步w.. 
// 看了下以前的代码..太鬼抽了ww...这个题按理来说除了字典序这个要想下其它就是板子了w.. 

typedef pair<string, int > PII;
// 没给范围RE了w... 
const int N = 550;
// DLRU
int mv[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
char pos[] = {'D', 'L', 'R', 'U'};
bool graph[N][N];
struct Node {
	int x, y, step;
	string path;
	Node (int x, int y, int step, string path) : x(x), y(y), step(step), path(path) {};
	Node () {};
} que[N * N];
int n, m;
PII bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0, "");
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == n - 1 && now.y == m - 1) return PII(now.path, now.step);
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (graph[nx][ny]) continue;
			graph[nx][ny] = true;
			que[++qback] = Node(nx, ny, now.step + 1, now.path + pos[i]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	PII res = bfs(0, 0);
	cout << res.second << endl << res.first;
	return 0;
}
/*
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

// 我谔谔，被这个题虐了，主要是方向写错了，出界写错了，感觉这还是不熟 

int graph[525][525];
bool visited[525][525];
struct Node {
	int x, y;
	string res;
	int cnt;
	Node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {};
};
queue<Node > que;
int n, m;
void bfs(Node node) {
	// visited[node.x][node.y] = true;
	// 题目要求顺序是上下左右... 
	// 但是要求字典序，所以这里要按照字典序来走，因为BFS一定是最短路，但是无法保证顺序
	int pos[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
	char posChar[] = {'D', 'L', 'R' , 'U'};
	visited[node.x][node.y] = true;
	// char posChar[] = {'U', 'D', 'L' , 'R'};
	node.res = "";
	que.push(node); 
	Node temp(0, 0, 0);
	string st;
	while(!que.empty()) {
		temp = que.front();que.pop();
		if (temp.x == n && temp.y == m) {
			cout << st.size() << endl << st;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = temp.x + pos[i][0], ny = temp.y + pos[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// 太池沼忘了加访问判断...I can not stop *it*! 
			if (visited[nx][ny] || graph[nx][ny]) continue;
			//temp.x = nx, temp.y = ny, temp.res += posChar[i], temp.cnt++;
			Node nNode(nx, ny, temp.cnt++);
			st += posChar[i];
			visited[nNode.x][nNode.y] = true;
			que.push(nNode);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs((Node){1, 1, 0});
	return 0;
}
*/
