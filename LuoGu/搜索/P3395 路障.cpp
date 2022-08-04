#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 这个题同样是数学坐标轴，同样是数学里的坐标点..，也就是说输出和输入等得反过来 

// 又被坑了ww，这次被坑在自己的输出上了，输入没有考虑数轴，但是输出考虑了数轴，由此导致的就是对着错误的输出
// 调了半天没有结果。

// 结论就是不管数轴怎么样，只要起点和终点的坐标找对了就行...也就是说输入可以不管，把题目的坐标轴的起点终点
// 对应到没有处理的输入就行... 

const int N = 1010;
struct PII {
	int x, y, step;
	PII(int x, int y, int step) : x(x), y(y), step(step) {};
	PII() {};
};
int graph[N][N];
PII que[N * N];
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;
// x实际是y轴，y实际是x轴，为了方便这个是反着的（结果输入没变化，输出反着的ww） 
string bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy, 0);
	// graph[sx][sy] = -1;
	//cout << endl;
	while (qtop <= qback) {
		PII now = que[qtop++];
		//cout << now.x << ' ' << now.y << ' ' << now.step << endl;
		if (now.x == n && now.y == n) return "Yes";
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			// cout << nx << ' ' << ny  << ' ' << now.step << ' ' << graph[nx][ny] << endl;
			if (graph[nx][ny] == -1 || now.step > graph[nx][ny] && graph[nx][ny] != 0) continue;
			graph[nx][ny] = -1;
			// cout << nx << ' ' << ny << ' ' << now.step << endl;
			que[++qback] = PII(nx, ny, now.step + 1);
		}
	}
	return "No";
} 

int main() {
	int T;
	scanf("%d", &T);
	int x, y;
	while (T--) {
		memset(graph, 0, sizeof graph);
		scanf("%d", &n);
		for (int i = 1; i <= 2 * (n - 1); i++) {
			scanf("%d%d", &x, &y);
			graph[x][y] = i;
		}
		
//		puts("");
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				printf("%d ", graph[i][j]);
//			}
//			puts("");
//		}
		cout << bfs(1, 1) << endl;
	}
	return 0;
}
