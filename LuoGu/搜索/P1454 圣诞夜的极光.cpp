#include <iostream>
#include <cstdio>
using namespace std;

// ��ˮ��䣬��Ŀ˵�������پ��룬����ʵ���Ͼ������������ڣ����ģ� ��ͨ������
// ���Կ������а˸�������ߣ�������BFSʵ�֣���ȻDFSҲ�� 

// ��������Ŷ�����ǵð���Ŀ�� 

// BFS��׳�ҳ�����ww 

// �����£���ν�������پ��������ԭ�еİ˸������ϼ����ĸ�����Ҳ���������������ĸ������������پ�����
// ���ĸ�������Զ���һ��

// ���鼯��ʵҲ��������ͨ��������⣬������һֱ���Ǻ���⣨���ܣ������������⻹����BFS��DFS������ 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110;
char graph[N][N];
PII que[N * N];
int n, m;
int move[12][2] = {
{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1},
{2, 0}, {-2, 0}, {0, 2}, {0, -2}
};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	graph[sx][sy] = '-';
	que[qtop] = PII(sx, sy);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 12; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (graph[nx][ny] != '#') continue;
			graph[nx][ny] = '-';
			que[++qback] = PII(nx, ny);
		}
	}	
}
int main() {
	cin >> n >> m;
	// ��gets�ӿ���룬��gets�����±�;���ͳһ��0��ʼ����Ϊ
	// �б�����Լ����ã������б�ֻ�ܴ�0��ʼ 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == '#') {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
