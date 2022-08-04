#include <iostream>
#include <queue>
using namespace std;

// 全WA三次，暂且蒙古 

// WA了四次，本地测试发现是输入输出出了问题，关闭同步流加速的cin，cout不知道为什么
// 对输入的字符不能结束 

const int N = 1010;
int n;
char graph[N][N];
int x1, y1, x2, y2;
struct Node {
	int x, y, step;
	Node () {};
	Node(int x, int y, int step) : x(x), y(y), step(step) {};
};
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs() {
	queue<Node > que;
	que.push(Node(x1, y1, 0));
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.x == x2 && now.y == y2) {
			cout << now.step << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (graph[nx][ny] != '0') continue;
			graph[nx][ny] = true;
			que.push(Node(nx, ny, now.step + 1)); 
		}
	} 
}
int main() {
	// 这里写了关闭同步流会导致无法结束输入，看到题解里也有人被坑了，暂且蒙在数据里 
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0) ;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 奇妙的错误，看起来输入01转布尔不能用c的输入输出来 
			cin >> graph[i][j];
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	bfs();
	return 0;
}
