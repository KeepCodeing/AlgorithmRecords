#include <iostream>
#include <queue>
using namespace std;

// FloodFill，用来求连通块，可以用BFS也可以用DFS，但是DFS存在爆栈的可能性，而且其之前也没用过
// BFS，所以这里用BFS写一遍，另外一般默认栈空间只有1M作用，如果递归占用内存小可能还可以递归很多次
// 如果每次递归都开很大的空间八成会爆栈 

// 太玄学了，BFS比DFS慢了一点点，但是内存占用居然更低，而且本five这次开了加快读写居然还慢了点w 

const int N = 110;
typedef pair<int, int > PII;
// 可以把pair的first和second用x，y代替，注意是用#define 
// #define x first;
// #define y second;
char graph[N][N];
int n, m;
int move[8][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
void bfs(int sx, int sy) {
	queue<PII > que;
	// 本来想着BFS只用存一次状态，现在看来还是以前对BFS的印象起了作用，摒弃以前的池沼想法，该了 
	que.push(PII(sx, sy));
	while (!que.empty()) {
		PII now = que.front();que.pop();
		for (int i = 0; i < 8; i++) {
			int nx = now.first + move[i][0], ny = now.second + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (graph[nx][ny] != 'W') continue;
			graph[nx][ny] = '.';
			// BFS如何做到只存一次状态呢？暂且蒙在鼓里（对以前想法的反问） 
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
