#include <iostream>
using namespace std;
const int N = 20;
int n, m;
int cnt = 0;
bool visited[N][N];
void dfs(int sx, int sy) {
	if (sx > n || sx < 0 || sy > m || sy < 0) return;
	if (visited[sx][sy]) return;
	if (sx == n && sy == m) cnt++;
	visited[sx][sy] = true;
	// ���˻ᣬ��Ϊ��ƶ���ռ����������ְ�����д���� 
	dfs(sx + 1, sy + 2);
	dfs(sx + 2, sy + 1);
	dfs(sx - 1, sy + 2);
	dfs(sx - 2, sy + 1);
	visited[sx][sy] = false;
}
int main() {
	cin >> n >> m;
	dfs(0, 0);
	cout << cnt;
	return 0;
}
