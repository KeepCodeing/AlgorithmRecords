#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#define endl '\n'
#define x first
#define y second
using namespace std;
const int N = 1e3 + 10;
char graph[N][N], res[N][N];

int n, m;

typedef pair<int, int > PII;

struct Node {
	int x, y, val;	
	bool operator> (const Node a) const {
		return val > a.val;
	}
	Node(int valt, int xt, int yt): val(valt), x(xt), y(yt) {};
};

map<PII, int > mp;
map<PII, PII > path;

// D = 1, D2 = sqrt(2)
// D * (dx + dy) + (D2 - 2 * D) * min(dx, dy)

//int cal_start(int nx, int ny) {
//	// x_dis = nx - 0, y_dis = ny - 0
//    // Distance to start point
//    return nx + ny - 2 + (sqrt(2) - 2) * min(nx, ny);
//}
//    
//
//int cal_end(int nx, int ny, int ex, int ey) {
////	  x_dis = self.map.size - 1 - p.x
////    y_dis = self.map.size - 1 - p.y
//	int x_dis = ex - 1 - nx;
//	int y_dis = ey - 1 - ny;
//    // Distance to end point
//    return x_dis + y_dis + (sqrt(2) - 2) * min(x_dis, y_dis);
//}
//    
//int g(int nx, int ny, int ex, int ey) {
//	return cal_start(nx, ny) + cal_end(nx, ny, ex, ey);
//}        

int mhd(int nx, int ny, int ex, int ey) {
	return abs(nx - ex) + abs(ny - ey);
}
        
int mv[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
// , {1, 1}, {-1, -1}, {1, -1}, {-1, 1}

int astar(int sx, int sy, int ex, int ey) {
	priority_queue<Node, vector<Node >, greater<Node > > que;
	mp[PII(sx, sy)] = 0;
	que.push(Node(0, sx, sy));
	while (que.size()) {
		Node now = que.top(); que.pop();
		if (now.x == ex && now.y == ey) {
			PII end = PII(ex, ey), start = PII(sx, sy);
			int tot = 0;
			while (end != start) {
//				cout << end.x << ' ' << end.y << endl;
				res[end.x][end.y] = '*';
				end = path[end];				
				tot++;
			}
			return tot;
		}
		for (int i = 0; i < 8; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			// the next point's cost
//			int c = cal_start(nx, ny);
//			int c = mhd(1, 1, nx, ny);
			int c = mp[PII(now.x, now.y)] + 1;
			// out boundary 
			if (nx < 1 || nx > 50 || ny < 1 || ny > 50) continue;
			if (graph[nx][ny] == 'x') continue;
			// haven't visit or cost can be samll
			if (!mp.count(PII(nx, ny)) || mp[PII(nx, ny)] > c) {
				mp[PII(nx, ny)] = c;
				path[PII(nx, ny)] = PII(now.x, now.y);
//				int f = g(nx, ny, ex, ey);
				int f = c + mhd(nx, ny, ex, ey);
				que.push(Node(f, nx, ny)); 
			}
		}
	}
	return 114514;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int sx, sy, ex, ey;
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			cin >> graph[i][j];
			res[i][j] = graph[i][j];
			if (graph[i][j] == 's') sx = i, sy = j;
			if (graph[i][j] == 'd') ex = i, ey = j;
		}
	}
	cout << astar(sx, sy, ex, ey) << endl;
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
	return 0;
}

/*
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
xxxxxxxxxxxxxxxxxxxxxxxxx.........................
........................x.........................
........................x..........xxxxxxx........
........................x..........x..............
...........s............x..........x..d...........
........................x..........x.....x........
........................x..........xxxxxxx........
........................x.........................
.................xxxxxxxxxxxxxxxxxxxxxxxxxxxx.....
..................x...............................
..................x...............................
..................x......xxxxxxxxxxxxxxxxxxxxxxxxx
..................x...............................
..................x...............................
.xxxxxxxxxxxxxxxxxxxxxxxxx........................
......................x...........................
......................x...........................
......................x...........................
......................x...........................
......................x...........................
......................xxxxxxxxxxxxxxxxxxxxxxxx....
.................................x................
.................................x................
......xxxxxxxxxxxxxxxxxxxxxxxxxxxx................
................x................x................
................x................x....xxxxxxxxxxxx
................x................x................
................x................xxxxxxxxxxx......
................x.................................
................x.................xxxxxxxxxxxxxxxx
................x.................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
*/
