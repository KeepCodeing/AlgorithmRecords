#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node  {
	int v, w;
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		// Prim�����Ľڵ��ţ�ֻ����Ȩֵ��С������д����� 
		// if (v != n.v) return v < n.v;
		return w > n.w;
	}
	
};
vector<Node > graph[5010];
priority_queue<Node > que;
int n, m;
int tot = 0, result = 0;
bool *visited;
void initVis(int n) {
	visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);
}
void prim(int start) {
	que.push((Node){start, 0});
	Node x(0, 0);
	// ���ӣ���whileд����if... 
	while (!que.empty() && tot < n) {
		x = que.top();que.pop();
		if (!visited[x.v]) {
			visited[x.v] = true;
			tot++;
			result += x.w;
			for (int i = 0; i < graph[x.v].size(); i++) {	
				if (!visited[graph[x.v][i].v]) {
					que.push(graph[x.v][i]);
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int u, v, w;
	int start;
	bool flag = true;
	initVis(n);
	while (m--) {
		cin >> u >> v >> w;
		if (flag) start = u, flag = !flag;
		graph[u].push_back((Node) {v, w});
		graph[v].push_back((Node) {u, w});
	}
	prim(start);
	// �ж��Ƿ���ֻͨ���ж����е��Ƿ����꼴�� 
	if (tot == n) cout << result;
	else cout << "orz";
	delete[] visited;
	return 0;
}
