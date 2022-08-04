#include <iostream>
using namespace std;

// 原来越界不是因为下标，而是因为其没有对访问过元素进行标记 

struct point {
	int x, y;
	point(int x1 = 0, int y1 = 0) {
		x = x1, y = y1;
	}
};
int numMap[20][20];
int m, n;
// 起始位置，终点 
int start_x, start_y, end_x, end_y;
// 存储走过的点 
point p;
point result[50000];
// 标记是否有解 
bool flag = false;
// 输出解 
void printResult(int deepth) {
	for (int i = 0; i < deepth; i++) {
		cout << "(" << result[i].x << "," << result[i].y << ")" << "->";
	}
	// 补上终点
	cout << "(" << end_x << "," << end_y << ")" << endl;
}
void dfs(int x, int y, int level) {
	if (x > m || x < 1 || y > n || y < 1) return;
	if (!numMap[x][y]) return;
	numMap[x][y] = 0;
	// 标记路径 
	p.x = x, p.y = y;
	// 添加路径 
	result[level] = p;
	if (x == end_x && y == end_y) {
		// 标记有解 
		flag = true;
		printResult(level);
		 
	}
	// 题目的顺序：左上右下，否则输出不一致 
	dfs(x, y - 1, level + 1);
	dfs(x - 1, y, level + 1);
	dfs(x, y + 1, level + 1);
	dfs(x + 1, y, level + 1);
	numMap[x][y] = 1;
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> numMap[i][j];
		}
	}
	cin >> start_x >> start_y;
	cin >> end_x >> end_y;
	// 终点不能走的特判
	if (numMap[end_x][end_y] != 1) {
		cout << "-1";
		return 0;
	} 
	dfs(start_x, start_y, 0);
	if (!flag) cout << "-1";
	return 0;
}
