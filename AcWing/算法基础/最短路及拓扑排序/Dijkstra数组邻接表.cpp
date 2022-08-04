#include <iostream>
#include <queue>
using namespace std;

// ��֮ǰд��vector���е㲻һ����������û���ýṹ���ˣ�
// ���priority_queue������ʽҲ�����Ȩֵ���ȣ����о���
// ѭ�����˸����ӣ����峤����BFS�� 

const int N = 100010, INF = 0x3FFFFFFF;
// �¼��˸�w����������Ȩ�� 
int head[N], e[N], ex[N], w[N], idx = 0;
void add(int k, int val, int wei) {
	e[idx] = val, w[idx] = wei, ex[idx] = head[k], head[k] = idx++;
}
// ����һ��pair�����涥���Ȩֵ���������
typedef pair<int, int > PII; 
// ������һ�����ʱ�����飬��Ȼ֮ǰ�Ӳ��Ӷ����� 
bool visited[N];
int dist[N];
int n, m;
int dijkstra() {
	dist[1] = 0;
	// ������� 
	priority_queue<PII, vector<PII >, greater<PII > > que; 
	// Ȩֵ��Ķ������ȣ��������˼�ǴӶ���1��ʼ�����1��1�ľ���Ϊ0 
	que.push(PII(0, 1));  
	while (!que.empty()) {
		PII t = que.top();que.pop();
		// ȡ�������ź�Ȩֵ 
		int v = t.second, distance = t.first;
		if (visited[v]) continue;
		// ��δ���ʹ��ĵ��� 
		visited[v] = true;
		// �������������б� 
		for (int i = head[v]; i != -1; i = ex[i]) {
			int j = e[i];
			// �Աȴӵ�ǰֱ�ӵ�j�������ͨ��v�㵽j��� 
			if (dist[j] > w[i] + distance) {
				dist[j] = w[i] + distance;
				// visited[i] = true;
				que.push(PII(dist[j], j)); 
			}
		} 
	}
	if (dist[n] == 0x3FFFFFFF) return -1;
	return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N, -1);
	fill(dist, dist + N, INF);
	cin >> n >> m; 
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	cout << dijkstra();
	return 0;
}

/*

����������
3 3
1 2 2
2 3 1
1 3 4
���������
3
*/
