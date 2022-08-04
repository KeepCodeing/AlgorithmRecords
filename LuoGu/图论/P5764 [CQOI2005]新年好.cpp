#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

// ����+���·
// ��Ŀ����˼�������ģ���1�ŵ㿪ʼ�����ο��Ե�a,b,c,d,e����һ���㣬����1->a��Ȼ���ٴ�a��ʣ�µĵ��е�����һ��
// Ҳ�������̶�������Ҫ�����������·ʹ�����ǵĺ���С
// ���Կ����ȶ�ÿ������һ�����·����ΪҪ����������������·����Ȼ��ö�����п��ܵ��߷�.. 

// RE��..�ɹ� 

typedef pair<int, int > PII;
const int N = 50000 + 10, M = 100000 * 2 + 10, INF = 0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int pos[10] = {1};
int dist[10][N];
bool visited[N];
void dijkstra(int st, int id) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	fill(dist[id], dist[id] + N, INF);
	fill(visited, visited + N, false);
	dist[id][st] = 0;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[id][vt] > wt + w[i]) {
				dist[id][vt] = wt + w[i];
				que.push(PII(dist[id][vt], vt)); 
			}
		}
	}
}
int main() {
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 5; i++) scanf("%d", &pos[i]);
	fill(head, head + N, -1);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	// Ϊ�˶�Ӧ����dist������±�Ҳ��1��ʼ 
	for (int i = 0; i <= 5; i++) dijkstra(pos[i], i + 1);
	int res = INF;
	do {
		int t = 0;
		for (int i = 1; i <= 4; i++) {
			//printf("%d ", pos[i]);
			if (pos[i] == i) {
				t = -1;
				break;
			}
			t += dist[pos[i]][pos[i + 1]]; 
			//printf("%d\n", dist[pos[i]][pos[i + 1]]);
		}
//		puts("");
//		puts("-----");
		if (t != -1) res = min(res, t + dist[1][pos[1]]);
		printf("%d %d\n", dist[1][pos[1]], pos[1]);
		break;
	} while (next_permutation(pos + 1, pos + 6));
//	for (int i = 0; i <= 5; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", dist[pos[i]][j]);
//		}
//		puts("");
//	}
	printf("%d", res);
	return 0;
}
