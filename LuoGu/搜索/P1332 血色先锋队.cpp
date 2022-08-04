#include <iostream>
#include <cstring>
using namespace std;

// ���е�С���⣬���������̾���ģ���еĶ�Դ��̾��룬ע�����Ǵ�Ϊ��1���ĵ㿪ʼ����������
// ����ͨBFS����û������ 

#define x first
#define y second
const int N = 510;
typedef pair<int, int > PII;
int n, m, a, b;
// ��dist��������¼����1�㵽��ǰ�ľ��� 
int dist[N][N];
PII que[N * N];
int qtop = 0, qback = 0;
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs() {
	// ��ͨBFS 
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1) continue;
			// ��һ����ľ��������һ����ľ����+1 
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> a >> b;
	int x, y;
	// dist����������ȳ�ʼ������Ȼ�����޷�����뻹���ж��Ƿ���� 
	memset(dist, -1, sizeof dist);
	// ����ͨBFS��һ���ĵط���Ҫ�ӡ�1������� 
	while (a--) {
		// ��� 
		cin >> x >> y;
		// С���⣺����д����qtop++���������������дbfs���ѭ��������ִ�� 
		que[qback++] = PII(x, y);
		// �Լ����Լ��ľ���Ϊ0������ͨ��dist���齫����Ϊδ���� 
		dist[x][y] = 0;
	}
	bfs();
	while (b--) {
		cin >> x >> y;
		// ��������̾������ 
		cout << dist[x][y] << endl;
	}
	return 0;
}
