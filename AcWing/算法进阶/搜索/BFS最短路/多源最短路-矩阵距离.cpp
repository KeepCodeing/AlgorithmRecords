#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;

// �����ĿҪ���������0��1��������룬�Ƚ����ص��뷨���Ƕ�ÿ��0����һ��bfs����������֪��
// bfs��ĳ�����һ�γ�����õľ��Ծ������·�������Կ��Է����룬��ÿ����1��ʼ������Ȼ�����
// ��0�ľ��� 

// ��������˸��⣬����������graph��ʵûʲô�ã�����˵��Դ���·ģ�͵���graph��ûʲô��
// ������ģ�͵�������graph���������������������Ԫ�أ�ֻ��dist���Ǵ����ͷ��ʷ������ 

#define x first 
#define y second 
typedef pair<int, int > PII;
const int N = 1010, M = N * N;
int n, m;
int dist[N][N];
char graph[N][N];
PII que[M];
int qtop = 0, qback = 0;
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs() {
	// ����bfs
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// ��Ϊ��һ�������ĵ������̾��룬����û��Ҫ�ظ����� 
			if (dist[nx][ny] != -1) continue;

			// ���¾��룬��ǰ���������һ�����+1 
			dist[nx][ny] = dist[now.x][now.y] + 1;
			cout << dist[nx][ny] << endl;
			// �ٴ�����㿪ʼ����
			que[++qback] = PII(nx, ny); 
		}
	}
} 
int main() {
	scanf("%d%d", &n, &m);
	// ֮ǰ��Ȼ��bfs���ʼ����dist���飬�������������û���� 
	memset(dist, -1, sizeof dist);
	cout << sizeof dist << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// ��scanf���ˣ�scanf�ѻ���Ҳ�������ַ������ˣ���ͼֱ�Ӷ��Ǹ���� 
			cin >> graph[i][j];
			if (graph[i][j] == '1') {
				// ��1��������ӣ�˳�㽫��1�ľ������㣬��Ϊ1���Լ��ľ������0 
				que[qback++] = PII(i, j);
				dist[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << dist[i][j] << ' ';
		cout << endl;
	}
	cout << qtop << ' ' << qback << endl;
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dist[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
3 4
0001
0011
0110

3 2 1 0
2 1 0 0
1 0 0 1
*/
