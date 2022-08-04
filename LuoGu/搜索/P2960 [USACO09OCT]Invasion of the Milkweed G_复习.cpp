#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// BFS��ϰ��һ���������ܿӣ����������ϣ�����˼·��ʵҲ��̫���룬���������˾�֪����·��... 
// ���������������ĵ�ͼ����������֮��ĵô����£��������LeetCode�ϵ���·�������ٱ���һ���ͼ��ֱ�ӷ������һ����
// ����������ʱ����У�������������Ҳ�Ƿ��ŵ�... 

// �����������ת�������ķ����ǰ��������ʱ�����е��ſ�ʼ�����������յ㣬��ͼ�Ͷ����ϼ���������... 
// Ȼ�������˵������ȫ��ȷ��˼���¼���������������ӣ����Է��ּ��������ǰ������y�������ˣ��������ʱ��y�Ӵ�С������.. 

// ��֪��Ϊʲôֱ�ӷ�����������һ�����������������Ǳ���������֮���ԭ�����Ի����ñ���ȡ���ֵ�ķ�������..w

// ��������ת��������˼·�����ύ����ʱ��������ǰ�Ĵ�����������ģ�������ʱ��û��ʲô��⣬���ڵ�����ȫ���ˣ��¹ʶ�֪����w 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110;
int n, m;
char graph[N][N];
PII que[N * N];
int dist[N][N];
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	memset(dist, -1, sizeof dist);
	dist[sx][sy] = 0;
	PII now;
	while (qtop <= qback) {
		now = que[qtop++];
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					int nx = now.x + i, ny = now.y + j;
					if (nx > n || nx < 1 || ny > m || ny < 1) continue;
					if (dist[nx][ny] != -1 || graph[nx][ny] == '*') continue;
					dist[nx][ny] = dist[now.x][now.y] + 1;
					que[++qback] = PII(nx, ny);
				}
			}
		}
	}
	return dist[now.x][now.y];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%d ", dist[i][j]);
//		}
//		puts("");
//	}
}
int main() {
	int sx, sy;
	// �������÷���������Ϊ����sx����Ϊ�б�ʹ�õģ�sy����Ϊ�б�ʹ�õģ�Ҳ�Ͷ�Ӧ����y��x�����Ե÷����� 
	scanf("%d%d%d%d", &m, &n, &sy, &sx);
	for (int i = n; i >= 1; i--) {
		// ע������m�������x���ϵ�Ԫ�أ�n�������y�ϵ�Ԫ�أ���������ת���������ļ��ɾ��ǰ�y�ᷴ����... 
		for (int j = 1 ; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	printf("%d", bfs(sx, sy));
	return 0;
}
