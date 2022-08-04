#include <iostream>
#include <cstring>
using namespace std;

// ��Ŀû˵Ҫ���·�������Ҵ𰸲�Ψһ������Ҫ����߹���·��
// ��ô�����BFS���������Է�����˳������·�� 

// ���̣��������������� 

#define x first
#define y second
const int N = 150, M = N * N;
typedef pair<int, int > PII;
char graph[N][N];
PII pre[N][N], que[M];
int r, c;
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	pre[sx][sy] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1) continue;
			if (pre[nx][ny].x != -1) continue;
			if (graph[nx][ny] != '.') continue;
			pre[nx][ny] = now;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
		}
	}
	memset(pre, -1, sizeof pre);
	// ����2��û�е����ѣ�һ��ʼ�������ѵ�... 
	bfs(r, c);
	// ����1��������ô���֮ǰд��(0, 0)��������ѭ�������������Ϊ�̳�������0��ʼ�����µĴ���ӡ��
	// (0, 0)û��pre��  
	PII end(1, 1);
	while (true) {
		cout << end.x << ' ' << end.y << endl;
		if (end.x == r && end.y == c) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
