#include <iostream>
#include <queue>
using namespace std;

// ȫWA���Σ������ɹ� 

// WA���ĴΣ����ز��Է�������������������⣬�ر�ͬ�������ٵ�cin��cout��֪��Ϊʲô
// ��������ַ����ܽ��� 

const int N = 1010;
int n;
char graph[N][N];
int x1, y1, x2, y2;
struct Node {
	int x, y, step;
	Node () {};
	Node(int x, int y, int step) : x(x), y(y), step(step) {};
};
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs() {
	queue<Node > que;
	que.push(Node(x1, y1, 0));
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.x == x2 && now.y == y2) {
			cout << now.step << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (graph[nx][ny] != '0') continue;
			graph[nx][ny] = true;
			que.push(Node(nx, ny, now.step + 1)); 
		}
	} 
}
int main() {
	// ����д�˹ر�ͬ�����ᵼ���޷��������룬���������Ҳ���˱����ˣ��������������� 
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0) ;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// ����Ĵ��󣬿���������01ת����������c����������� 
			cin >> graph[i][j];
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	bfs();
	return 0;
}
