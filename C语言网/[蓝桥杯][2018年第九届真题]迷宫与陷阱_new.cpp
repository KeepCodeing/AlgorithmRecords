#include <iostream>
using namespace std;

// �ո�BFSдд�귢�������⣬����������Ϊ�߹��ĵ�Ͳ��������ˣ�Ҳ����BFS�����߻�ͷ·�������Ļ������ܱ�֤ö�ٵ������е�״̬��
// ȥ����Ƿ��ʹ����ܵõ���ȷ�𰸣�Ȼ�������ظ���״̬�ֱ�÷ǳ��࣬���ȫRE��w... 

const int N = 1010;
int md = 0x3fffffff;
int n, k;
char graph[N][N];
void dfs(int x, int y, int step, int kt) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (graph[x][y] == '#' || (graph[x][y] == 'X' && kt <= 0)) return;
	if (x == n - 1 && y == n - 1) {
		md = min(md, step);
		return;
	}
	char temp = graph[x][y];
//	if (graph[x][y] != 'X') graph[x][y] = '#';
	if (graph[x][y] == '%') kt += k;
	dfs(x + 1, y, step + 1, kt);
	dfs(x, y + 1, step + 1, kt);
	dfs(x - 1, y, step + 1, kt);
	dfs(x, y - 1, step + 1, kt);
	if (graph[x][y] != '%') graph[x][y] = temp;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	dfs(0, 0, 0, 0);
	cout << md;
	return 0;
} 
