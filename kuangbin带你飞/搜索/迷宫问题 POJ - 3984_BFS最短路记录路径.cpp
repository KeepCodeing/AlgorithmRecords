#include <iostream>
#include <cstring>
using namespace std;

// д�����⣬֮ǰfuxi����������w����˵�����ֻ��һ�����ݵ㣬��ˮ��w��ĿǰΨһһ���ܿ�����д������һ��AC����... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 10;
int graph[N][N];
PII que[N * N], pre[N][N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int sx, int sy) {
	// ��������Ϊ-1ֻ��Ϊ���ж��Ƿ��߹����������·����ʱ����Ҫ���������յ�Ϊ��... 
	memset(pre, -1, sizeof pre);
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy); 
	pre[sx][sy] = PII(-1, -1);
	while (qtop <= qback) {
		PII now = que[qtop++];
		// if (now.x == 0 && now.y == 0) return;���ﲻ����ǰ���أ���Ȼ��¼��·�������� 
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			// ��Ҫ����1������ 
			if (graph[nx][ny]) continue;
			if (pre[nx][ny].x != -1) continue;
			pre[nx][ny] = now;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	bfs(4, 4);
	// ���յ���BFS���յ��ܵ����յ������㣬�ٴ������ݻ�ȥ��ԭ·��... 
	PII end = PII(0, 0);
	while (true) {
		cout << "(" << end.x <<", " << end.y << ")" << endl;
		// �ߵ��յ�ֹͣ������==-1�ж���û�߹����������γ���ѭ�� 
		if (end.x == 4 && end.y == 4) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
