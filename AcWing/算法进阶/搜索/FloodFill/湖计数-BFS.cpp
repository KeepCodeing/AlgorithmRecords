#include <iostream>
#include <queue>
using namespace std;

// FloodFill����������ͨ�飬������BFSҲ������DFS������DFS���ڱ�ջ�Ŀ����ԣ�������֮ǰҲû�ù�
// BFS������������BFSдһ�飬����һ��Ĭ��ջ�ռ�ֻ��1M���ã�����ݹ�ռ���ڴ�С���ܻ����Եݹ�ܶ��
// ���ÿ�εݹ鶼���ܴ�Ŀռ�˳ɻᱬջ 

// ̫��ѧ�ˣ�BFS��DFS����һ��㣬�����ڴ�ռ�þ�Ȼ���ͣ����ұ�five��ο��˼ӿ��д��Ȼ�����˵�w 

const int N = 110;
typedef pair<int, int > PII;
// ���԰�pair��first��second��x��y���棬ע������#define 
// #define x first;
// #define y second;
char graph[N][N];
int n, m;
int move[8][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
void bfs(int sx, int sy) {
	queue<PII > que;
	// ��������BFSֻ�ô�һ��״̬�����ڿ���������ǰ��BFS��ӡ���������ã�������ǰ�ĳ����뷨������ 
	que.push(PII(sx, sy));
	while (!que.empty()) {
		PII now = que.front();que.pop();
		for (int i = 0; i < 8; i++) {
			int nx = now.first + move[i][0], ny = now.second + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (graph[nx][ny] != 'W') continue;
			graph[nx][ny] = '.';
			// BFS�������ֻ��һ��״̬�أ��������ڹ������ǰ�뷨�ķ��ʣ� 
			que.push(PII(nx, ny)); 
		}
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] != '.') {
				cnt++, bfs(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}
