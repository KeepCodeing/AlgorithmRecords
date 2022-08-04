#include <iostream>
#define endl '\n'
using namespace std;
const int N = 25;
char graph[N][N];
bool vx[N], vy[N];
int n, m;
void dfs(int x, int y) {
	// ը���ĵ㣨���ʵ��ˣ��ͱ���޷���ը��״̬ 
	graph[x][y] = '0';
	// �����һ��û�з��ʹ����ͱ�����һ�е����е㣬�ҵ�
	// ����һ��ը����Ȼ�������ʼ������չ 
	if (!vx[x]) {
		vx[x] = true;
		for (int i = 0; i < m; i++) {
			if (graph[x][i] == '1') {
				dfs(x, i);
			}
		}
	}
	// ͬ��������չ 
	if (!vy[y]) {
		vy[y] = true;
		for (int i = 0; i < n; i++) {
			if (graph[i][y] == '1') {
				dfs(i, y);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int ans = 0;
	// ������ͨ��Ĳ��������￼�ǵĲ��������Ǹ�ը����������ը
	// ���ټ���ը���������ж������Ǹ�ը���γɵ���ͨ������ 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == '1') {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
