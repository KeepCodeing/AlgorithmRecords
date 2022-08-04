#include <iostream>
#include <cstdio>
using namespace std;

// �� �� ��

// �Ƚ����������ô�ж϶Խ��ߺ�ˮƽλ�õĻʺ��Ƿ�Ź�
// ��ͼ���Կ�������һ���Խ��ߵĽؾ�Ϊb = x + y����һ��
// �Խ��ߵĽؾ�Ϊb = y - x�����������±����磬����
// ��ƫ��������ͼ��С����ȥ�ؾ༴b = n - (y - x) = n + x - y  
 
const int N = 13;

char graph[N][N];
bool col[N], dg[N], udg[N];
int n;
void dfs(int y) {
	if (y == n) {
		// ������ɣ���putsֱ�ӽ�char[][]�����ַ������ 
		for (int i = 0; i < n; i++) puts(graph[i]);
		puts("");
		return;	
	}
	for (int i = 0; i < n; i++) {
		if (!col[i] && !dg[y + i] && !udg[n - y + i]) {
			// ���·���״̬�������i�ʹ���ĺ�����x 
			col[i] = dg[i + y] = udg[n + i - y] = true;
			graph[y][i] = 'Q';
			dfs(y + 1);
			col[i] = dg[y + i] = udg[n - y + i] = false;
			graph[y][i] = '.';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = '.';
		}
	}
	dfs(0);
	return 0;
}
