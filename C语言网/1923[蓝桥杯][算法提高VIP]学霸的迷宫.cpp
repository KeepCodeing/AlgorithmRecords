#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

// �����̣��������Ű�ˣ���Ҫ�Ƿ���д���ˣ�����д���ˣ��о��⻹�ǲ��� 

int graph[525][525];
bool visited[525][525];
struct Node {
	int x, y;
	string res;
	int cnt;
	Node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {};
};
queue<Node > que;
int n, m;
void bfs(Node node) {
	// visited[node.x][node.y] = true;
	// ��ĿҪ��˳������������... 
	// ����Ҫ���ֵ�����������Ҫ�����ֵ������ߣ���ΪBFSһ�������·�������޷���֤˳��
	int pos[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
	char posChar[] = {'D', 'L', 'R' , 'U'};
	visited[node.x][node.y] = true;
	// char posChar[] = {'U', 'D', 'L' , 'R'};
	node.res = "";
	que.push(node); 
	Node temp(0, 0, 0);
	string st;
	while(!que.empty()) {
		temp = que.front();que.pop();
		if (temp.x == n && temp.y == m) {
			cout << st.size() << endl << st;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = temp.x + pos[i][0], ny = temp.y + pos[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// ̫�������˼ӷ����ж�...I can not stop *it*! 
			if (visited[nx][ny] || graph[nx][ny]) continue;
			//temp.x = nx, temp.y = ny, temp.res += posChar[i], temp.cnt++;
			Node nNode(nx, ny, temp.cnt++);
			st += posChar[i];
			visited[nNode.x][nNode.y] = true;
			que.push(nNode);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs((Node){1, 1, 0});
	return 0;
}
