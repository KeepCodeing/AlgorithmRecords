#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra�����ȶ��п��Թ����������·������ǿ����TLE������ǿ��������ݸ���
// vector��С�˻�RE��... 

struct Node {
	int v, w;
	// ���ֳ�ʼ����ʽҲҪ�ṩ���� 
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
// ��Ŀ�г����˱�3F3F3F3F���ֵ��Ҳ����int�����ֵ����������INF�������Ϊint�����ֵ7FFFFFFF 
const int INF = 0x7FFFFFFF;
int n, m, s;
int *dist;
bool *visited; 
vector<Node > graph[10010];
priority_queue<Node > que;

void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node){start, dist[start]}); 
	Node x(0, 0), y(0, 0);
	while(!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			// ����������������˼���ж������ľ���ֵ�Ƿ�ȵ�ǰ�����ֵ����������Ȩֵ 
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				// ����֮ǰд����dist[y.w]... 
				que.push((Node){y.v, dist[y.v]}); 
			}
		}
	}
}
void initArray(int n) {
	visited = new bool[n + 1];
	dist = new int[n + 1];
	fill(visited, visited + n + 1, false);
	fill(dist, dist + n + 1, INF);
}
int main() {
	cin >> n >> m >> s;
	// ���˳�ʼ������.. 
	initArray(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w}); 
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) cout << dist[i] << (i != n ? " " : "");
	delete[] visited, dist;
	return 0;
}
