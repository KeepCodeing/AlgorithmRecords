#include <iostream>
#include <queue>
using namespace std;

// ��Ŀ����˼�Ƚ����ԣ�����Ҫ��һ���㣬ʹ�����������㵽�����ľ�����С�����������ȫԴ���·����
// �������ݷ�Χȴ�Ƚϴ���˿����뵽��ÿ������һ�ε�Դ���·��Ȼ��Ա���̾��뼴�ɡ�
// floyd O(n^3) Dijkstra O(mlogn) SPFA O(n*m)

const int N = 810, M = 1460 * 2 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[M];
int pos[N];
bool visited[N];
int n, p, c, t;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	// ע��ÿ�������·��Ҫ��ԭ��������ͷ��ʱ������.. 
	fill(dist, dist + M, INF);
	fill(visited, visited + N, 0);
	// dijkstra���ӣ���ÿ���������·.. 
	dist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	int res = 0;
	// ͳ�Ƶ�ǰ�㵽������ţ���ڵ������ľ��룬������ɴ�˵���õ㲻�ǺϷ��� 
	for (int i = 1; i <= n; i++) {
		if (dist[pos[i]] == INF) return INF;
		res += dist[pos[i]];
	}
	return res;
}
int main() {
	cin >> n >> p >> c;
	fill(head, head + N, -1);
	for (int i = 1; i <= n; i++) cin >> pos[i];
	int ut, vt, wt;
	for (int i = 1; i <= c; i++) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt), add(vt, ut, wt);
	} 
	int res = INF;
	// һ��p���㣬n��������ţ����1~p֮������е������·��Ȼ�󷵻� 
	// ��Щ�㵽�����ľ���֮�ͣ�֮ǰ���˸�set����Ϊ��Ŀ��˵�п�����
	// ĳ��������ֹһ����ţ���������ܿ������󼸴����·��.. 
	for (int i = 1; i <= p; i++) {
		res = min(dijkstra(i), res);
	}
	cout << res;
	return 0;
}

/*
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5

8
*/
