#include <iostream>
using namespace std;

// AtCoder�Ϻ����кܶ�ˮ������ӣ����ĸУ����ߴ�ǰ��ˮ��w �������ߴ���������ҵ�ſ�ʼ..��
// �ƺ�BFSд��̫���ˣ�����������һ�ۻ�����дBFS��Ȼ�����ǵ��������Լ����ܻ�����DFS���� 

const int N = 510;
char graph[N][N];
int sx, sy, ex, ey;
int n, m;
bool flag = false;
void dfs(int sx, int sy) {
	if (sx > n || sx < 1 || sy > m || sy < 1) return;
	if (graph[sx][sy] == '#') return;
	if (sx == ex && sy == ey) {
		flag = true;
		return;
	}
	// ֻ�����ܲ��ܵ��յ�������ݣ�Ҫͳ���߷�������Ҫ���ݣ�ԭ����
	// ������DFS����BFS����������һ������������ͼ������ֻ���ж���û��
	// ���ܵ��յ���� 
	graph[sx][sy] = '#';
	dfs(sx + 1, sy);
	dfs(sx - 1, sy);
	dfs(sx, sy + 1);
	dfs(sx, sy - 1);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 's') sx = i, sy = j;
			if (graph[i][j] == 'g') ex = i, ey = j;
		}
	}
	dfs(sx, sy);
	if (flag) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
} 
