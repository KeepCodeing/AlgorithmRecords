#include <iostream>
#include <vector>
using namespace std;
// 因为只有0和1，所以玩点骚操作 
struct Node {
	int x, y;
	Node (int x, int y) : x(x), y(y) {};
};
int minStep = 0x3FFFFFFF;
bool graph[7][7];
vector<Node > vec;
vector<Node > res;
void dfs(int x, int y, int step) {
	// 喜闻乐见的剪枝 
	if (step >= minStep) return;
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return;
	if (graph[x][y]) return;
	if (x == 4 && y == 4) {
		// 放结果，可能这样消耗时间会更多，但是其也没办法在DFS里记录最短路径 
		res.clear();
		// 没想到矢量可以直接赋值，STL IS GOD 
		res = vec;
		// 每次都更新一个最小值，再加上前面的剪枝，就能剔除步数大的路径了 
		minStep = min(minStep, step);
		return;
	}
	// 标记走过，以及添加路径 
	graph[x][y] = true;
	vec.push_back((Node){x, y});
	dfs(x + 1, y, step + 1);
	dfs(x - 1, y, step + 1);
	dfs(x, y + 1, step + 1);
	dfs(x, y - 1, step + 1);
	vec.pop_back();
	graph[x][y] = false;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 0, 0);
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << '(' << res[i].x << ", " << res[i].y << ')' << endl;
	}
	// 终点单独输出，不过还要注意这里,是有空格的... 
	cout << '(' << 4 << ", " << 4 << ')';
	return 0;
} 
