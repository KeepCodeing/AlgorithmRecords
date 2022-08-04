#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 啊啊，只能刷水题了（挫败感），加油吧da☆ze 

// 思路：先找到能到终点的路，再判断这个路径是否能到三夫人处
// 能，更新最短路径 

// 正解应该是BFS...，迫真DFS超时了，看起来这种求最短路径的题还是得用BFS（废话） 

struct Node {
	int x, y;
	Node(int x, int y) : x(x), y(y) {};
};
bool graph[55][55];
vector<Node > path;
int sx, sy, ex, ey;
int tx, ty;
int n, m;
int minStep = 0x3FFFFFFF;
void dfs(int sx, int sy, bool flag, int step) {
	// 之前加了个最短路径的剪枝，但是到达的了终点的最短路径不一定就刚好经过三夫人 
	// 但是使用标记法之后就能判断了 
	if (flag && step >= minStep) return;
	if (sx < 0 || sx >= n || sy < 0 || sy >= m) return;
	if (graph[sx][sy]) return;
	if (sx == ex && sy == ey && flag) {
		minStep = min(minStep, step);
		// 扫一遍，看下经过三夫人没，改用用一个flag来标记 
//		for (int i = 0; i < path.size(); i++) {
//			if (path[i].x == tx && path[i].y == ty) {
//				
//				break;
//			} 
//		}
		return;
	}
	graph[sx][sy] = true;
	if (sx == tx && sy == ty) flag = true;
	// path.push_back((Node){sx, sy});
	dfs(sx + 1, sy, flag, step + 1);
	dfs(sx - 1, sy, flag, step + 1);
	dfs(sx, sy + 1, flag, step + 1);
	dfs(sx, sy - 1, flag, step + 1);
	// path.pop_back();
	graph[sx][sy] = false;
}

int main() {
	cin >> n >> m;
	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == 'S') sx = i, sy = j;
			else if (temp == 'T') tx = i, ty = j;
			else if (temp == 'E') ex = i, ey = j;
			else graph[i][j] = temp - '0';
		}
	}
	// 偷懒用bool存的地图，所以要把三个特殊点的位置标记为可走 
	graph[tx][ty] = graph[ex][ey] = graph[sx][sy] = false;
	dfs(sx, sy, false, 0);
	cout << minStep;
	return 0;
}
