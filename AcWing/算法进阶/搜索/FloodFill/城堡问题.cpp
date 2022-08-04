#include <iostream>
using namespace std;

// �����Ǹ�FloodFill�⣬����������ճ����˸���ͼ��ģ����ƺ��������� 

// ��first��secondת��Ϊx��y 
#define x first
#define y second
const int N = 55, M = N * N;
typedef pair<int, int > PII;
int graph[N][N];
int n, m;
bool visited[N][N];
// ������ģ����� 
PII que[M];
// ˳��������������£�����ֱ��Ӧ���������� 
int move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int bfs(int sx, int sy) {
	// ��β����ǰԪ�أ�hhҲ��������ͨ��Ĵ�С 
	int tt = 0, hh = 0;	
	int area = 0;
	que[0] = PII(sx, sy);
	// ������ 
	visited[sx][sy] = true;
	while (hh <= tt) {
		// ȡ����ͷԪ�� 
		PII now = que[hh++];
		int k = graph[now.x][now.y];
		area++;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			// �����жϣ����ʹ��жϣ��ĸ������Ƿ���ǽ 
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (visited[nx][ny]) continue;
			if (k >> i & 1) continue;
			visited[nx][ny] = true;
			// ���Ԫ�� 
			que[++tt] = PII(nx, ny);
			
		}
	}
	return area;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt  = 0, maxArea = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				cnt++;
				maxArea = max(maxArea, bfs(i, j));
			}	
		}
	}
	cout << cnt << endl << maxArea;
	return 0;
}
/*
4 7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13

5 9
*/
