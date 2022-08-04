#include <iostream>
#include <queue>
using namespace std;

// һ��ʼ�����и������ߵĲ������ûᳬʱ��Ȼ������ⷢ�����ݺ�ˮ��
// Dijkstra���ܹ�... 

// ���̣�����ao�࣬����������vector���... 

// RE�����Σ�ʵ�ڲ�֪���ߺ͵������С�ķ����ϵ�����ڿ���������ĺܴ�Ӧ����û�����... 
// �����������ܾ��Ƕ���ͷ�������Ĵ�С���Ը���n�������Ƕ������������������������
// ���ø���m����Ҳ���Ǳ���������������ǳ�2+10�� 

const int N = 110, M = 100010, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[M], w[M], e[M], ex[M], idx = 0;
void add(int k, int v1, int w1) {
	e[idx] = v1, w[idx] = w1, ex[idx] = head[k], head[k] = idx++;
}
int dist[M];
bool visited[M];
int n, m;
void dijkstra(int st) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	// ������ΪʲôҪ��pair�棬������ʵ��Ϊ�˷���֮����� 
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (!que.empty()) {
		PII t = que.top();que.pop();
		int ver = t.second, wei = t.first;
		if (visited[ver]) continue;
		visited[ver] = true;
		for (int i = head[ver]; i != -1; i = ex[i]) {
			int j = e[i];
			// j�ǵ�ǰ�� 
			if (dist[j] > w[i] + wei) {
				dist[j] = w[i] + wei;
				que.push(PII(dist[j], j));
			}
		} 
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N, -1);
	cin >> n >> m;
	int u, v, w;
	while (m--) {
		int op;
		cin >> op;
		if (op) {
			cin >> u >> v >> w;
			// ����ͼ 
			add(u, v, w), add(v, u, w);
		} else {
			cin >> u >> v;
			dijkstra(u);
			if (dist[v] != 0x3fffffff) cout << dist[v];
			else cout << -1;
			cout << endl;
		}
	} 
	return 0;
} 
