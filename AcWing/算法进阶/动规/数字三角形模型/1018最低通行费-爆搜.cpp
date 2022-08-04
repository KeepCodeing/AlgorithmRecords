#include <iostream>
using namespace std;

// ���Ѱ棺�������Թ����⣬��һ����ʱ��֦�����յ������С���� 
// ��������û�����յ�Ļ��ѣ����о��Ǳ�Ƿ���ֱ�Ӹ��˵�ͼ������
// ��ͼ��ĳ��Ҫ�ظ��õ���������������

// ������Ѱ�Ҳ���Ըĳɼ��仯�����������䲻��www 

const int N = 110;
int graph[N][N];
bool visited[N][N];
int n;
int ans = 0x3fffffff;
void dfs(int sx, int sy, int t, int money) {
	if (t < 0) return;
	if (sx > n || sx < 1 || sy > n || sy < 1) return;
	if (visited[sx][sy]) return;
	if (sx == n && sy == n) {
		//cout << money << endl;
		// ���˼����յ��Ǯ������ʵ�������������յ��Ǯ�Ǳ��뽻�� 
		ans = min(ans, money + graph[sx][sy]);
		return;
	}
	// ԭ��������ͨ���ĵ�ͼ�ķ�ʽ����Ƿ��ʵģ����ǲ�֪��Ϊʲô
	// �����˸��ķǷ��� 
	visited[sx][sy] = true;
	dfs(sx + 1, sy, t - 1, money + graph[sx][sy]);
	dfs(sx - 1, sy, t - 1, money + graph[sx][sy]);
	dfs(sx, sy + 1, t - 1, money + graph[sx][sy]);
	dfs(sx, sy - 1, t - 1, money + graph[sx][sy]);
	visited[sx][sy] = false;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(1, 1, 2 * n - 1, 0);
	cout << ans << endl;
	return 0;
}
