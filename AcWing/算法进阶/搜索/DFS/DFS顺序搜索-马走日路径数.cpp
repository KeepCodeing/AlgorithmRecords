#include <iostream>
#include <cstring>
using namespace std;

// Ҫ��������ж�ĳ�������߱�ȫͼ������������ͨDFS���� 

const int N = 15;
int n, m, sx, sy;
int ans = 0;
bool graph[N][N];
int move[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
void dfs(int sx, int sy, int cnt) {
	if (sx > n || sx < 1 || sy > m || sy < 1) return;
	if (graph[sx][sy]) return;
	graph[sx][sy] = true;
	// �����ǰÿ���㶼�߹��ˣ���˵����������ǿ��� 
	// ע������û��return������return��һ���ߵ��յ�Ͳ�������������� 
	if (cnt == n * m - 1) ans++;
	for (int i = 0; i < 8; i++) {
		int nx = sx + move[i][0], ny = sy + move[i][1];
		dfs(nx, ny, cnt + 1);
	}
	graph[sx][sy] = false;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> sx >> sy;
		ans = 0;
		memset(graph, false, sizeof graph);
		dfs(sx + 1, sy + 1, 0);
		cout << ans << endl;
	}
	return 0;
}
/*
1
5 4 0 0

32
*/
