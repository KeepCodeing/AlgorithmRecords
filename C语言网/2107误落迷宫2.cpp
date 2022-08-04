#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ������ֻ��ˢˮ���ˣ���ܸУ������Ͱ�da��ze 

// ˼·�����ҵ��ܵ��յ��·�����ж����·���Ƿ��ܵ������˴�
// �ܣ��������·�� 

// ����Ӧ����BFS...������DFS��ʱ�ˣ����������������·�����⻹�ǵ���BFS���ϻ��� 

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
	// ֮ǰ���˸����·���ļ�֦�����ǵ�������յ�����·����һ���͸պþ��������� 
	// ����ʹ�ñ�Ƿ�֮������ж��� 
	if (flag && step >= minStep) return;
	if (sx < 0 || sx >= n || sy < 0 || sy >= m) return;
	if (graph[sx][sy]) return;
	if (sx == ex && sy == ey && flag) {
		minStep = min(minStep, step);
		// ɨһ�飬���¾���������û��������һ��flag����� 
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
	// ͵����bool��ĵ�ͼ������Ҫ������������λ�ñ��Ϊ���� 
	graph[tx][ty] = graph[ex][ey] = graph[sx][sy] = false;
	dfs(sx, sy, false, 0);
	cout << minStep;
	return 0;
}
