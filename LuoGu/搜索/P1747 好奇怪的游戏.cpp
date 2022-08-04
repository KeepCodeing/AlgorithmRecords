#include <iostream>
#include <cstring>
using namespace std;

// 裸BFSw，为什么之前没做呢，因为本five看到马可以走日也可以走田便以为要分情况讨论，然而都已经开始写爆搜了
// 为何不把所有可能走一遍呢w，也就是走法数组需要存马和象的走法，除此之外没有别的了... 

// 然而CE了一次，因为move数组和内置变量冲突了... 

const int N = 30;
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
};
bool graph[N][N];
Node que[N * N];
// 搞了ao久的移动数组（指对着抄） 
int mv[12][2] = {{1, -2}, {1, 2}, {2, -2}, {2, -1}, {2, 1}, {2, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {-2, -2}, {-2, 2}};
void bfs(int x, int y) {
	int qtop = 0, qback = 0;
	que[qtop] = Node(x, y, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == 1 && now.y == 1) {
			cout << now.step << endl;
			return;
		}
		for (int i = 0; i < 12; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > 20 || ny < 1 || ny > 20) continue;
			if (graph[nx][ny]) continue;
			graph[nx][ny] = true;
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
}
int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	bfs(x1, y1);
	memset(graph, 0, sizeof graph);
	cin >> x2 >> y2;
	bfs(x2, y2);
	return 0;
}
