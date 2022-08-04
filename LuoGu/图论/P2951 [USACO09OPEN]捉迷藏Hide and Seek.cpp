#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����SPFA�ٶ���죬�������ܱ����� 

struct Node {
	int v, w;
	// �ݣ������w(w)д����w(v)����������
	// Ȩֵ����˱�Ŷ�����Ĭ�ϵ�1 
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m;
int *dist;
vector<Node > graph[20010];
priority_queue<Node > que;
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
} 
void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node){start, 0});
	Node x(0, 0), y(0, 0);
	while (!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				que.push((Node){y.v, dist[y.v]});
			}
		}
	} 
} 
int main() {
	cin >> n >> m;
	initArr(n);
	int u, v;
	while(m--) {
		cin >> u >> v;
		// ����������ͼ
		// ��Ŀû��Ȩֵ���������Կ�����Ĭ��Ϊ1 
		graph[u].push_back((Node){v, 1});
		graph[v].push_back((Node){u, 1});
	}
	dijkstra(1);
	// ��������о���֮�����һ�α�������ȡ���ֵ���ٽ���һ�α���
	// �������ֵ���Լ���һ���������ֵ��Ԫ�ص��±�
	int maxDist = -1, firstIndex = 0, maxDistCnt = 0; 
	for (int i = 1; i <= n; i++) maxDist = max(maxDist, dist[i]);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == maxDist) {
			if (firstIndex == 0) firstIndex = i;
			maxDistCnt++;
		}
	}
	cout << firstIndex << ' ' << maxDist << ' ' << maxDistCnt;
	delete[] dist;
	return 0;
}
