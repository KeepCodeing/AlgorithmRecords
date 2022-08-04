#include <iostream>
using namespace std;

// 刚刚BFS写写完发现有问题，想了下是因为走过的点就不能再走了，也就是BFS不能走回头路，这样的话它不能保证枚举到了所有的状态，
// 去掉标记访问过就能得到正确答案，然而这样重复的状态又变得非常多，结果全RE了w... 

const int N = 1010;
int md = 0x3fffffff;
int n, k;
char graph[N][N];
void dfs(int x, int y, int step, int kt) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (graph[x][y] == '#' || (graph[x][y] == 'X' && kt <= 0)) return;
	if (x == n - 1 && y == n - 1) {
		md = min(md, step);
		return;
	}
	char temp = graph[x][y];
//	if (graph[x][y] != 'X') graph[x][y] = '#';
	if (graph[x][y] == '%') kt += k;
	dfs(x + 1, y, step + 1, kt);
	dfs(x, y + 1, step + 1, kt);
	dfs(x - 1, y, step + 1, kt);
	dfs(x, y - 1, step + 1, kt);
	if (graph[x][y] != '%') graph[x][y] = temp;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	dfs(0, 0, 0, 0);
	cout << md;
	return 0;
} 
