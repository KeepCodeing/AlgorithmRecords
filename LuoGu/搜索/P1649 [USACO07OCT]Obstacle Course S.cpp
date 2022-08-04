#include <iostream>
using namespace std;

// 思路是记录上一次走的方向，如果不同就说明要拐弯了 
// 想了下DFS做的情况，用一个参数记录上一次的方向， 然后
// 把所有路径都走一遍，这样一定能得出解，但是步数越多，拐弯
// 的几率就越大，所以不如用一个BFS，同样是对比方向，但是因为
// 走到终点就绝对是最短路，所以转弯的几率也是最小的，因此用
// BFS只要方向不同就可以记录 

// 另外需要注意下怎么判断走不到终点，应该可以通过bfs的返回值来
// 如果能走到，返回的绝对是一个大于等于0的数，否则默认返回-1 

// 我谔谔，坠毁了，可能和方向有关系 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110, M = N * N;
int n;
// 这里同样不用标记访问过，只用将走过的字符改了就行 
char graph[N][N];
int sx, sy, ex, ey;
// 感觉要存三个元素，所以这里用个结构体 
// 实际上要存五个元素，以为其不知道怎么退出上一次走的方向，所以这里还要存下方向 
// 当然可以把方向转为字符，但是直接用move里的数据应该也行 
struct Node {
	int x, y;
	string path;
	Node () {};
	Node (int x, int y, string path) : x(x), y(y), path(path) {};
};
Node que[M];
int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int getCnt(string str) {
	cout << str << endl;
	// 开头的方向不算，因为起始位置方向不限
	int sLen = str.size();
	int cnt = 0;
	int j = 1;
	// 双指针统计有多少个不连续字符 
	for (int i = 1; i < sLen; i++) {
		while (str[i] == str[j]) j++;
		cnt++;
		// 依旧是这个地方有点不记得 
		i = j - 1;
	} 
	return cnt;
} 
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, "");
	// 估计起点表不标记都无所谓，这里先不标记试试
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey) return getCnt(now.path);
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			if (graph[nx][ny] != '.') continue;
			graph[nx][ny] = 'x';
			// 脑子突然开窍，其实可以记录下每次走的方向，有多少个字符不同就说明走拐了多少弯路 
			que[++qback] = Node(nx, ny, now.path + char(i + 65)); 
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'A') sx = i, sy = j, graph[i][j] = '.';
			if (graph[i][j] == 'B') ex = i, ey = j, graph[i][j] = '.';
		}
	}
	cout << bfs();
	return 0;
} 
