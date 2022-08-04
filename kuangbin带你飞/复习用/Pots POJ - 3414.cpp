#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

// BFS枚举状态.. 
// 其写的似乎是在原版进行了改进，更简洁了...也说明状态枚举没有白学w.. 

struct Node {
	int x, y, op, step;
	Node (int x, int y, int op, int step) : x(x), y(y), op(op), step(step) {};
	Node () {};
};
stack<Node > res;
queue<Node > que;
const int N = 100 + 10;
bool visited[N][N];
Node pres[N][N];
int a, b, c;
void print(Node now) {
	
	// cout << pres[now.x] << ' ' << pres[now.y] << endl;
	res.push(now);
	while (true) {
		cout << now.x << ' ' << now.y << endl;
		if (now.op == 0) break; 
		res.push(pres[now.x][now.y]);
		now = pres[now.x][now.y];
		cout << now.x << ' ' << now.y << endl;
	} 
//	while(res.size()) {
//		Node temp = res.top();
//		res.pop();
//		cout << temp.op << endl;
//	}
}
void bfs() {
	// 神奇的memset，就算是结构体也能正常初始化... 
	memset(pres, -1, sizeof pres);
	que.push(Node(0, 0, 0, 0));
	while (que.size()) {
		Node now = que.front();que.pop();
		if (now.x == c || now.y == c) {
			cout << now.step << endl;
			print(now);
			return;
		}
		// 枚举六个状态1：装满A；2：装满B，3：倒空A；4；倒空B；5：A倒B；6：B倒A。 
		for (int i = 1; i <= 6; i++) {
			Node nx = Node(now.x, now.y, i, now.step + 1);
			switch(i) {
				case 1 : nx.x = a; break;
				case 2 : nx.y = b; break;
				case 3 : nx.x = 0; break;
				case 4 : nx.y = 0; break;
				case 5 : nx.y = min(b, now.y + now.x), nx.x = max(0, now.x - (b - now.y)); break;
				case 6 : nx.x = min(a, now.x + now.y), nx.y = max(0, now.y - (a - now.x)); break;
			}
			if (!visited[nx.x][nx.y]) {
				que.push(nx);
				pres[nx.x][nx.y] = now;
				visited[nx.x][nx.y] = true;
			}
		} 
	}
	cout << "impossible" << endl;
}

int main() {
	cin >> a >> b >> c;
	bfs();
	return 0;
}
