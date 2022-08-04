#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

// BFSö��״̬.. 
// ��д���ƺ�����ԭ������˸Ľ����������...Ҳ˵��״̬ö��û�а�ѧw.. 

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
	// �����memset�������ǽṹ��Ҳ��������ʼ��... 
	memset(pres, -1, sizeof pres);
	que.push(Node(0, 0, 0, 0));
	while (que.size()) {
		Node now = que.front();que.pop();
		if (now.x == c || now.y == c) {
			cout << now.step << endl;
			print(now);
			return;
		}
		// ö������״̬1��װ��A��2��װ��B��3������A��4������B��5��A��B��6��B��A�� 
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
