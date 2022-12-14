#include <iostream>
#include <vector>
using namespace std;

// 想了下用BFS跑迷宫估计比较麻烦，因为有个传送机制，因此不如将其当成一个图，然后跑最短路... 
// 然而发现自己不知道怎么建图，所以一开始干脆写了个BFS，然后发现可以跑过测试数据，但是交了却WA了很多点 
// 然后就一直在排错，排了半天似乎也没怎么改动代码，然后看题解发现思路是一样的，又开始对拍，发现也没问题
// 最后发现是一个地方写错了..果然代码五分钟，排错一小时，傻逼错误大多都是因为编码不仔细... 

// 那么这个题本质还是个BFS，但是加了个传送门，由此可以直接在输入的过程中处理掉，走到传送门就将这个传送门能去的另一个点 
// 入队就行了。然后注意这是个双向边，但是可以发现走到另一个传送再回来不会有什么影响，因为这个传送门能走的情况已经被走过了.. 

typedef pair<int, int > PII;
typedef pair<PII, PII > PPII;
const int N = 350;
char graph[N][N];
bool vis[N][N];
vector<PII > csm[30];
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
} que[N * N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int sx, sy, ex, ey;
int n, m;
bool isalp(char a) {
	return 'A' <= a && a <= 'Z';
}
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey) {
			cout << now.step << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (graph[nx][ny] == '#' || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			// 如果是传送门，将它能到的点入队 
			if (isalp(graph[nx][ny])) {
//				cout << nx << ' ' << ny << ' ' << graph[nx][ny] << endl;
				// 判断是从哪个传送门过来的，然后传送过去... 
				PII p1 = csm[graph[nx][ny] - 'A'][0], p2 = csm[graph[nx][ny] - 'A'][1];
				// 这里写成了nx == p1.first, ny == p2.second 
				if (nx == p1.first && ny == p1.second) que[++qback] = Node(p2.first, p2.second, now.step + 1);
				else que[++qback] = Node(p1.first, p1.second, now.step + 1);
			}
			else que[++qback] = Node(nx, ny, now.step + 1);
			
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			// 处理起点终点的位置 
			if (graph[i][j] == '@') sx = i, sy = j;
			if (graph[i][j] == '=') ex = i, ey = j;
			// 把传送门存起来，开始打算用个pair套pair，但是这样要很多判断，所以干脆改成vector了，反正一种传送门只有两个 
			if (isalp(graph[i][j])) csm[graph[i][j] - 'A'].push_back(PII(i, j));
		}
	}
//	for (int i = 0; i < 26; i++) {
//		for (int j = 0; j < csm[i].size(); j++) {
//			PII t = csm[i][j];
//			cout << t.first << ' ' << t.second << ' ' << (char)('A' + i) << endl;
//		}
//	}
	bfs(sx, sy);
	return 0;
}
/*
10 200
########################################################################################################################################################################################################
=.B####.#.##....#..###.#.#.#######Y#.#.##.####K..I###....####.#####.####.#.#.########.#...#F#####.##..####......#.##.#######..##.#.#######.#..###.#F......P###..##..##..#.###..###.#.####M.#.###.##.####
####.######.D######..#.#####S.####P#...##.##.##########.##.##.####.##...#########.#.##...#..J.#..#.#.#..######.#N####.##.###.....L####.L..#..#EE#..#.#..###.####..#####..#...Q#####.#####K..#.##.####..#
#######.#.#..#.#...###..##I...#####.#####.####..##.#####.#####..#####.##..#..####.#######.....#..##.#####.#####..#...###.....#####.#..#...#.#...G#...###...##...####.#####....#.##########....#####...##
######.#.#..###..##.##.##.#########.####.#.#.#.###.#.#.###..R##.#.####.####.#.#..####..###########.###.##.#.Q###.#.##.##..####..#####.##B###..#..##..#####.###...##..########.####.#.#..###.##J.##..#..#
##X...#.##...###..########...#.#.##.###......#####.#####.#A####.##.#.##.#..###.##..#####....######..#...####..##.#H..#O...###.##..##.####.#.#.##N.#.####.########..####.##.##..###########...##X#..#..##
#####.###..###.###.#####....##.####.####.#.#..#.#..###.###..###.#.#####..###.###...###.#####.####.##.###...#.#..###.#############.##.##..###.#G##.##..######..###.###.#.####.####.###.###.#..##...##.###
###A..##..#####..#..#.###.##...#YC#.#O...##.#..........######.###..#.#.####.###..#######....##..#.###.#..#..#...##.##M..#.#..#...#.##.####.##.#S####.###.##..#.#######.######.#D######.#..#......###..##
######R..#.###.##.#.#.##.###..######.##..#.##..#####..Z###..#H.#.####.#.#.#.#ZC##...#...#.....###.#..###...#####.###..##.####..##.#.##..#####.##########.#.#..#.#...####.####...###...##...#..###.#...@#
########################################################################################################################################################################################################
*/
