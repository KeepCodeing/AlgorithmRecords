#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1010;
int n, m;
bool graph[N][N];
bool visited[N][N];
int x, y;
struct Node {
	int x, y;
	Node () {};
	Node (int x, int y) : x(x), y(y) {};
};
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// ��д��һ����ʼ����������ĺ�������֪��Ϊʲôfill��ʼ����ά�����е�����
// ����������в��� 
void initVisited() {
	for (int i = 0; i < n + 5; i++) {
		for (int j = 0; j < n + 5; j++) visited[i][j] = false;
	}
}
int bfs() {
	int res = 0;
	queue<Node > que;
	que.push(Node(x, y));
	// ��Ϊ���Ǻ�������Ŀһ��ֱ�Ӹĵ�ͼ���������Ҫ������ 
	visited[x][y] = true;
	Node now;
	while (!que.empty()) {
		res++;
		now = que.front();que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (visited[nx][ny]) continue;
			if (graph[nx][ny] == graph[now.x][now.y]) continue;
			visited[nx][ny] = true;
			que.push(Node(nx, ny)); 
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char temp;
			// �ƺ�����ֱ����C��scanf����C++�Ĳ���ֵ����Ȼ���԰�
			// ����ֵ�������Σ�������ȵ������ȴ��0�� 
			scanf("%c", &temp);
			graph[i][j] = temp - '0';
		}
	}
	while (m--) {
		cin >> x >> y;
		initVisited();
		int ans = bfs();
		if (!ans) ans = 1;
		cout << ans << endl;
	}
	return 0;
}
