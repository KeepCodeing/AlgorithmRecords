#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int v, w;
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
vector<Node > graph[2510];
priority_queue<Node > que;
int n, m, s, t;
int *dist;
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
}
void dijkstra(int start) {
	// �������˳�ʼ�������룬�����������Ա��־��Ǿ�������ȫ��Ϊ��ʼֵ 
	dist[start] = 0;
	que.push((Node){start, 0});
	Node x(0, 0), y(0, 0);
	while (!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > y.w + dist[x.v]) {
				dist[y.v] = y.w + dist[x.v];
				// ����Ӧ���ǽ��õ������������Ϊһ���µĵ���� 
				que.push((Node){y.v, dist[y.v]}); 
			}
		} 		
	}
}
int main() {
	cin >> n >> m >> s >> t;
	initArr(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		// �����ˣ������Ǹ�����ͼ... 
		graph[v].push_back((Node){u, w});
	}
	dijkstra(s);
	cout << dist[t];
	delete[] dist;
	return 0;
}
