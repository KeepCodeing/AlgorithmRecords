#include <iostream>
#include <queue>
using namespace std;
int n;
int g[1000][1000], visited[1000];
queue<int > que;
int main() {
	int m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else g[i][j] = -1;
		}
	}
	int x, y;
	for (int i =1; i <= m; i++) {
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}
	// ��ӵ�һ��Ԫ�� 
	visited[1] = 1;
	que.push(1); 
	int cur;
	while (!que.empty()) {
		// ȡ����ǰԪ�� 
		cur = que.front();
		que.pop();
		cout << cur << endl;
		// ��ÿ���ڵ���б��� 
		for (int i = 1; i <= n; i++) {
			// �����ǰ�ڵ�û�б����ʹ�����ͨ· 
			if (!visited[i] && g[cur][i] != -1) {
				// ��Ӹýڵ㣬��������б�� 
				que.push(i);
				visited[i] = 1; 
			}
		}
	}
	return 0;
}
