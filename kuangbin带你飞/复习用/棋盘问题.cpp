#include <iostream>
using namespace std;
const int N = 10;
char graph[N][N];
bool visited[N];
int res;
void dfs(int level, int n, int cnt, int mx) {
	if (cnt == mx) {
		res++;
		return;
	}
	// 直接保证下次从下一行开始，这样行就绝对不会重复 
	for (int i = level; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 题目说的是行列都不能有相同棋子，这里只考虑了行.. 
			if (graph[i][j] == '#' && !visited[j]) {
//				graph[i][j] = '.'; 这个似乎没什么用...
				// 把当前这一列标记，防止走到同一列上了... 
				visited[j] = true;
				dfs(i + 1, n, cnt + 1, mx);
//				graph[i][j] = '#';
				visited[j] = false;
			}
		}
	}
}
int main() {
	int n, k;
	while (cin >> n >> k, n != -1)  {
		res = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) cin >> graph[i][j];
		dfs(0, n, 0, k); 
		cout << res << endl;
	} 
	 
	return 0;
}
