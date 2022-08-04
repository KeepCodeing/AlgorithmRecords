#include <iostream>
#include <queue>
using namespace std;
int n;
int airport[1000][1000], visited[1000];
queue<int > que;

// 坠毁ww，原因不明 

int main() {
	int m;
	int start, end;
	cin >> n >> m >> start >> end;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) airport[i][j] = -1;
			else airport[i][j] = 0;
		}
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		// 注意这里是无向图 
		airport[x][y] = 1;
		airport[y][x] = 1;
	}
	visited[1] = start;
	que.push(start);
	int cur, cnt = 0;
	bool flag = false;
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && airport[cur][i] != -1) {
				visited[i] = 1;
				cnt++;
				que.push(i); 
			}
			if (que.front() == end) {
				flag = true;
				break;
			}
		}
		cout << cnt << endl;
		if (flag) break;
	} 
	// cout << cnt << endl;
	return 0;
}
/*
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/
