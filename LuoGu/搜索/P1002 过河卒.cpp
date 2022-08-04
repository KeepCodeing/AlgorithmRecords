#include <iostream>
using namespace std;

// ao����ǰ�����ˣ���ʱ����ȫ���ȶ�ww 

// Ȼ������Ҳ��w��д�˸�DFS׹����w�����⶯�棬Ȼ������������ģ�����ƺ�ֻ�������ֵ�������󷽰����������ƺ�Ҳ��
// ����ww 

const int N = 30;
bool graph[N][N];
int cnt = 0;
int n, m, mx, my;
bool checker(int x, int y) {
	return x > n || x < 0 || y < 0 || y > m;
}
void dfs(int sx, int sy) {
	if (checker(sx, sy)) return;
	if (graph[sx][sy]) return;
	if (sx == n && sy == m) {
		cnt++;
		return;
	}
	graph[sx][sy] = true;
	dfs(sx + 1, sy);
	dfs(sx, sy + 1);
	graph[sx][sy] = false;
}
int move[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
int main() {
	cin >> n >> m >> mx >> my;
	graph[mx][my] = true;
	for (int i = 0; i < 8; i++) {
		int nx = mx + move[i][0], ny = my + move[i][1];
		if (checker(nx, ny)) continue;
		graph[nx][ny] = true;
	}
	dfs(0, 0);
	cout << cnt;
	return 0;
}
