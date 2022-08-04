#include <iostream>
using namespace std;
int n, minDis = 114514;
int city[1000][1000], visited[1000];
// ��ǰλ�ú����߾��� 
void dfs(int cur, int dis) {
	// ��֦�������ǰ���߾����Ѿ���������С���룬�Ͳ��ü������� 
	if (dis >= minDis) return;
	// ���������Ŀ�ĵأ��͸�����̾��� 
	if (cur == n) {
		minDis = min(dis, minDis);
		return;
	}
	// ��ÿ���ڵ���б��� 
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && city[cur][i] != -1) {
			visited[i] = 1;
			// �����߲��Ҹ��¾��� 
			dfs(i, dis + city[cur][i]);
			visited[i] = 0;
		}
	}
	return;
}
int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) city[i][j] = -1;
			else city[i][j] = 0;
		}
	}
	int x, y, w;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		// ��Ϊ������ͼ������һ����ֻ�ܵ�����ĵ���һ����
		city[x][y] = w; 
	}
	visited[1] = 1;
	dfs(1, 0);
	cout << minDis << endl;
	return 0;
}
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
