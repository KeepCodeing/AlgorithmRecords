#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ���ǰ��쿴������Ŀw��������˵�����Ҫ��ľ��Ǵ�1�ŵ㵽���е����̾��룬ͬʱ��Ҫ�󻨷���С������ǰ����Ǹ�
// ��������ܸ�Dijkstra�������ˣ�����α�֤����Ҳ��С�أ������²��ֱ��������˼·��һ��̰�ģ������Լ۱Ƚ�������
// ��ô����������ǲ���Ҳ�����������ţ��ƺ����У��������������Ǵ�ģ�������Ȼ���Խ�������˼·���������ڱ�֤����
// ��̵�ǰ���£����������·��������ͬ��ѡ�û�����С���Ǹ�������..
// ��˵����������С����������������������ģ���С������Ҫ���Ȩ����С�����·Ҫ��·�����... 
// ׹��.. 

const int N = 10000 + 10, M = 20000 * 2 + 10;
int head[N], e[M], ex[M], w[M], d[M], idx = 0;
int dist[N], cost[N];
int n, m;
bool visited[N];
void add(int ut, int vt, int wt, int dt) {
	e[idx] = vt, w[idx] = wt, d[idx] = dt, ex[idx] = head[ut], head[ut] = idx++;
}
struct Node {
	int ut, wt, dt;
	Node (int ut, int wt, int dt) : ut(ut), wt(wt), dt(dt) {};
	Node () {};
	// ע�������const 
	bool operator<(const Node& n) const {
		if (wt != n.wt) return wt > n.wt;
		return dt > n.dt;
	}
	bool operator>(const Node& n) const {
		
	}
};
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(cost, 0x3f, sizeof cost);
	memset(visited, 0, sizeof visited);
	priority_queue<Node, vector<Node >, greater<Node > > que;
	que.push(Node(st, 0, 0));
	dist[st] = 0, cost[st] = 0;
	while (que.size()) {
		Node now = que.top();que.pop();
		cout << now.ut << ' ' << now.wt << ' ' << now.dt << endl;
		int ut = now.ut, wt = now.wt, dt = now.dt;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				
				// cout << d[i] << ' ' << vt << endl;
				que.push(Node(vt, dist[vt], cost[vt])); 
			}
			cost[vt] = min(dt + d[i], cost[vt]);
		}
	} 
	for (int i = 1; i <= n; i++) cout << cost[i] << ' ';
	cout << endl;
	return 0;
}
int main() {
	int ut, vt, wt, dt;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		// �������ݣ����Ҫ��γ�ʼ��������Ӧ�ò��ó�ʼ������ͷ���������������飬ֻ�ø���idx���� 
		memset(head, -1, sizeof head);
		idx = 0;
		while (m--) {
			scanf("%d%d%d%d", &ut, &vt, &wt, &dt);
			// ˫��ߣ����ﻹҪ��Ӹ��������ԣ�һ��ʼ��Ϊ�����ø��ṹ��֮��Ķ����棬���������ƺ������У�ֻ��
			// ����Ҫ�õ�ʱ�����... 
			add(ut, vt, wt, dt), add(vt, ut, wt, dt);
		}
		printf("%d\n", dijkstra(1));
	}
	return 0;
}
