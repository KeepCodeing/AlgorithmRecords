#include <iostream>
using namespace std;
const int infinite = 114514;
int sumNum = 0, n;
int g[1000][1000], visited[1000];
void dfs(int cur) {
	cout << cur << endl;
	// ͳ������Щ�ڵ㱻������ 
	sumNum++;
	// ���ÿ���ڵ㶼�������˾ͽ������� 
	if (sumNum == n) return;
	// ��ÿ���ڵ���б��� 
	for (int i = 1; i <= n; i++) {
		// �����ǰ�ڵ㵽��һ���ڵ���·�Ҹýڵ�δ������ 
		if (g[cur][i] == 1 && !visited[i]) {
			visited[i] = infinite;
			dfs(i);
		}
	}
	return;
}
int main() {
	int m;
	cin >> m >> n;
	// ��ʼ��ͼ 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				// �Լ����Լ��ľ���Ϊ0 
				g[i][j] = 0;
			} else {
				// �����ȳ�ʼ��Ϊ���� 
				g[i][j] = infinite;	
			}
		}
	}
	int x, y;
	// ����� 
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		// �����ͨ· 
		g[x][y] = 1;
		// ��Ϊ������ͼ������x���Ե�y��yҲ���Ե�x
		g[y][x] = 1;
	}
	visited[1] = 1;
	dfs(1);
	return 0;
}
/*
5 5
1 2
1 3
1 5
2 4
3 5
*/
