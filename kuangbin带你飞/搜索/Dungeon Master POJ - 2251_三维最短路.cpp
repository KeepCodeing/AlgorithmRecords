#include <iostream>
using namespace std;

// ֻ������ά���·��ˢ��������֪��ԭ����άҲ���������·��˼·����
// �����������֮��Ķ�����ö��x, y, z������.. 
// BFS������ȻҲ��С�����ο���ά��w... 

const int N = 35, M = 6;
char graph[N][N][N];
int sx, sy, sz, ex, ey, ez;
int l, r, c;
// ���Կ�������ԭ�е��ĸ������϶����һ������... 
int x[M] = {1, -1, 0, 0, 0, 0}, y[M] = {0, 0, 1, -1, 0, 0}, z[M] = {0, 0, 0, 0, 1, -1};
struct Node {
	int x, y, z, step;
	Node (int x, int y, int z, int step) : x(x), y(y), z(z), step(step) {};
	Node () {};
} que[N * N * N + 100];
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, sz, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey && now.z == ez) return now.step;
		for (int i = 0; i < M; i++) {
			// ����һ�����λ�� 
			int nx = x[i] + now.x, ny = y[i] + now.y, nz = z[i] + now.z;
			// ע������ĳ����жϣ����鷳��������һ�㶼��ֱ�Ӹ��������ѭ���������Ǳ�����˼��.. 
			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
			if (graph[nx][ny][nz] == '#') continue;
			graph[nx][ny][nz] = '#';
			que[++qback] = Node(nx, ny, nz, now.step + 1);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (true) {
		cin >> l >> r >> c;
		if (!l && !r && !c) break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> graph[i][j][k];
					// ��¼�����յ�.. 
					if (graph[i][j][k] == 'S') sx = i, sy = j, sz = k;
					if (graph[i][j][k] == 'E') ex = i, ey = j, ez = k;
				}
			}
		}
		int res = bfs();
		if (res == -1) cout << "Trapped!";
		else cout << "Escaped in " << res << " minute(s).";
		cout << endl;
	}
	return 0;
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###
*/
