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
