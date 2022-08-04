#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 上一个又坠毁了w，看到很多代码都不用数组模拟的，这次也不用数组好了... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 1000 + 10;
char graph[N][N];
queue<PII > fire, peop;
int fd[N][N], pd[N][N];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m;
bool isout(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}
// 计算火的蔓延时间 
void bfs1() {
	while (fire.size()) {
		PII now = fire.front();fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (isout(nx, ny) || fd[nx][ny] != -1 || graph[nx][ny] == '#') continue;
			fd[nx][ny] = fd[now.x][now.y] + 1;
			fire.push(PII(nx, ny)); 
		}
	}
}
// 计算人是否能走出迷宫
int bfs2() {
	while (peop.size()) {
		PII now = peop.front();peop.pop();
		// 如果到达了边界点，就说明可以走出去，而不用真的走出去才判断，另外因为走出去还要一步，因此答案要+1 
		if (now.x == 0 || now.x == n - 1 || now.y == 0 || now.y == m - 1) return pd[now.x][now.y] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (isout(nx, ny) || pd[nx][ny] != -1 || graph[nx][ny] == '#') continue;
			// 这里判断火的距离是否是-1是因为还有墙，或者自己或者出界之类的情况.. 
			if (fd[nx][ny] != -1 && pd[now.x][now.y] + 1 >= fd[nx][ny]) continue;
			pd[nx][ny] = pd[now.x][now.y] + 1;
			peop.push(PII(nx, ny)); 
		}
	}
	return -1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		memset(fd, -1, sizeof fd);
		memset(pd, -1, sizeof pd);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == 'F') fire.push(PII(i, j)), fd[i][j] = 0;
				else if (graph[i][j] == 'J') peop.push(PII(i, j)), pd[i][j] = 0;
			}
		}
		bfs1();
		int res = bfs2();
		if (res != -1) cout << res;
		else cout << "IMPOSSIBLE";
		cout << endl;
		// 注意清空队列，因为出界了就直接返回了
		while (fire.size()) fire.pop();
		while (peop.size()) peop.pop(); 
	}
	return 0;
}
