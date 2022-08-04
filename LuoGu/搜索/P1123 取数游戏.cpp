#include <iostream>
using namespace std;

int graph[10][10];
bool visited[10][10];
void dfs(int level, int deepth, int breadth, int tot, int sx, int sy) {
	if (level == deepth - 1) {
		cout << tot << endl;
		return;
	}
	for (int i = level; i < deepth; i++) {
		int ny = i + 1;
		if (ny < deepth)
		for (int j = 0; j < breadth; j++) {
			if (j != sx - 1 && j != sx + 1 && !visited[i][j]) {
				visited[i][j] = true;
				dfs(i + 1, deepth, breadth, tot + graph[i][j], j, sy);
				visited[i][j] = false;
			}	
		}
//		int ny = level + 1;
//		if (ny < deepth) {
//			for (int i = 0; i < breadth; i++) {
//				tot += graph[ny][i];
//			}
//		}
	}
}

int main() {
	int t;
	cin >> t;
	int n, m;
	while(t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
			}
		}
		dfs(0, n, m, 0, 0, 0);
	}
	return 0;
} 
