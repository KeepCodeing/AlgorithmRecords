#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �Ż��Ĳ��־���ÿ��ȥdist����������������ǿ飬��for�Ҹ��Ӷ�ΪO(n)��
// �����ȶ����Ҹ��Ӷ�ΪO(logn) 

struct node {
	int v, weight;
	node(int v, int weight) : v(v), weight(weight) {};
//	node(int v1, int w1) {
//		v = v1, weight = w1;
//	}
	bool operator<(const node& n) const {
		// �ṩ���ȶ���������򣬶���С����ǰ��Ȩֵ�����ǰ 
		if (v != n.v) return v < n.v;
		return weight > n.weight;
	}
	
};
int n, m, s;
const int INF = 0x3F3F3F3F;
vector<node > graph[10010];
bool *visited;
int *dist;
priority_queue<node > que; 

void dijkstra(int start) {
	// ����㿪ʼ�ɳڱ� 
	dist[start] = 0;
	que.push((node){start, dist[start]}); 
	// ע������ĳ�ʼ������Ȼû�취��node 
	node x(0, 0), y(0, 0);
	while (!que.empty()) {
		// ȡ���ڵ�����С����Ȩֵ��ߵĶ��� 
		x = que.top();que.pop();
		// ��������������е���ͨ�� 
		for (int i = 0; i < graph[x.v].size(); i++) {
			// ȡ���ö������ͨ���� 
			y = graph[x.v][i];
			// ��ʼ�ɳڣ����ж���㵽Ŀǰ�����ľ����Ƿ��������������Ȩֵ+������Ȩֵ
			// ������ڣ����¸�С�ľ���ֵ��Ȼ������������� 
			if (dist[y.v] > dist[x.v] + y.weight) {
				dist[y.v] = dist[x.v] + y.weight;
				que.push((node){y.v, dist[y.v]});
			}
		}
	}
}
// memset���ܶ����������ʼ��Ϊ0����-1֮���ֵ����Ϊ���ǰ��ֽ�����ʼ���� 
void initArray(int n) {
	// for (int i = 1; i <= n; i++) visited[i] = false, dist[i] = INF;
	// fill���Զ��������͵������ʼ����fill(ָ��, ��ʼ����С�� ֵ) 
	visited = new bool[n + 1];
	dist = new int[n + 1];
	fill(visited, visited + n, false);
	fill(dist, dist + n, INF);
}
int main() {
	// ͼ��С�����������
	cin >> n >> m >> s;
	// ��ʼ������ 
	initArray(n);
	// <u,v>��Ȩֵ 
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back((node){v, w});
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) cout << dist[i] << (i != n ? " " : "");
	delete[] visited, dist;
	return 0;
}
