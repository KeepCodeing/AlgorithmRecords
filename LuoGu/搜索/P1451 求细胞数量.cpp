#include <iostream>
#include <cstdio>
using namespace std;

// ����...����Ŀû���壬ԭ���Ǹ�����ͨ����⣨���գ���0����ϸ����ֻ��1~9����ϸ�� 
// ����������ַ��ķ�ʽ��ʼ����ͼ�𰸲���ȷ������Ҳ��ѧ����һ��ֻ��һλ���ֵ��＼ 

int m, n; 
int graph[101][101];
void dfs(int x, int y) {
	if (x > m || x < 0 || y > n || y < 0) return;
	if (graph[x][y]) {
		graph[x][y] = 0;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}	
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
