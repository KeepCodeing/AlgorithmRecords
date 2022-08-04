#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 这个题应该就是跑两次BFS，然后记录两个起点到@的距离，最后对比最小值再相加就行了..这里用数组可能比较麻烦，因此
// 用STL模拟好了... 

// 做完了发现题目要求的其实是一个点两个人到的时间和最小，而不是所有点两个人到的时间和最小...还有就是有的点可能两个
// 人都到不了，这就是坑了..如果不加判断答案绝对会错的w 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 200 + 10;
int n, m;
// 用来存放两个起点的坐标 
PII start[2];
char graph[N][N];
// 存放两次BFS的距离 
int _dist[N][N], __dist[N][N];
// bool visited[N][N];
// 用来存放终点坐标 
PII eds[N * N + 10];
void bfs(PII st, int dist[N][N]) {
	// 两次BFS，所以访问数组要多次初始，但是dist数组不行，因为这里直接当指针传进来的 
	// 突然发现不需要visited数组，因为dist数组就能起到访问否的功能了.. 
	//memset(visited, 0, sizeof visited);
	queue<PII > que;
	que.push(st);
	// 注意初始化距离数组 
	dist[st.x][st.y] = 0;
	while (que.size()) {
		PII now = que.front();que.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				// 四向搜 
				if ((i != 0 || j != 0) && i != j && i != -j) {
					int nx = now.x + i, ny = now.y + j;
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; 
					if (graph[nx][ny] == '#') continue;
					if (dist[nx][ny] != -1) continue;
					// 这里就不能直接改地图了，因为地图会多次使用 
					// visited[nx][ny] = true;
					dist[nx][ny] = dist[now.x][now.y] + 1;
					que.push(PII(nx, ny));
				}
			}
		}
	}
}
int main() {
	int cnt;
	while (cin >> n >> m) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				// 各种处理，起点的处理，终点的处理... 
				if (graph[i][j] == 'Y') {
					// 把起点分别存起来 
					start[0] = PII(i, j);
					// 题目说Y和M也算障碍点 
					graph[i][j] = '#';
				}
				if (graph[i][j] == 'M') {
					start[1] = PII(i, j);
					graph[i][j] = '#';
				}
				// 把终点存起来，方便后面直接查询里那个起点到目前的终点距离最短.. ends居然冲突了... 
				if (graph[i][j] == '@') eds[cnt++] = PII(i, j);
			}
		}
		// 这里跑两遍BFS 
		int res = INT_MAX;
		memset(_dist, -1, sizeof _dist);
		memset(__dist, -1, sizeof __dist);
		bfs(start[0], _dist);
		bfs(start[1], __dist);
		PII tp;
		for (int i = 0; i < cnt; i++) {
			tp = eds[i];
			// 坑点：可能有一些点两个人都到不了（应该不存在只有一个人能到的点），这样的话裸的判断就会导致
			// 答案出现负数...然后就WA了w 
			if (_dist[tp.x][tp.y] == -1 || __dist[tp.x][tp.y] == -1) continue;
			res = min((_dist[tp.x][tp.y] + __dist[tp.x][tp.y]) * 11, res);
		}
		cout << res << endl;
	}
	return 0;
}
