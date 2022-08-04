#include <iostream>
#include <cstring>
using namespace std;

// ��BFSw��Ϊʲô֮ǰû���أ���Ϊ��five�������������Ҳ�����������ΪҪ��������ۣ�Ȼ�����Ѿ���ʼд������
// Ϊ�β������п�����һ����w��Ҳ�����߷�������Ҫ���������߷�������֮��û�б����... 

// Ȼ��CE��һ�Σ���Ϊmove��������ñ�����ͻ��... 

const int N = 30;
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
};
bool graph[N][N];
Node que[N * N];
// ����ao�õ��ƶ����飨ָ���ų��� 
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
