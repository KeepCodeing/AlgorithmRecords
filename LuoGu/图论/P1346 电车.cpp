#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

// ���ⶼû������...��������˼���Ǹ�N�����룬ÿ������K���㣬���е�i�����K == 0ʱ��
// �Ǹ���ֱ����������ȨΪ0�����������е�����������ȨΪ1����Ȼ�������·... 

// ���˰����������ҵ���...ԭ���ǿռ俪С��w���������ʱ���һֱ�����ǲ���������⣬��Ϊ֮ǰҲ���ӹ�...
// ������Ŀû����������N�����ݣ�ÿ������K����Ҳ���������100 * 100�����ݣ������Ǿ�100��... 

typedef pair<int, int > PII;
const int N = 1000 + 10;
int head[N], e[N], ex[N], w[N], idx = 0;
int dist[N];
bool vis[N];
int n, s, t, vt, k;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top(); que.pop();
		int ut = now.second, wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
	if (dist[ed] == 0x3f3f3f3f) return -1;
	return dist[ed];
}
int main() {
	memset(head, -1, sizeof head);
	memset(dist, 0x3f, sizeof dist);
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d", &vt);
			// ��һ����ֱ����������ȨΪ0������ĵ��ȨΪ1��ע�����ﲻ��ʡȥw���飬��Ϊ
			// ��Ȩ��ֹһ�����.. 
			if (j == 1) add(i, vt, 0);
			else add(i, vt, 1);
		}
	}
	printf("%d", dijkstra(s, t));
	return 0;
}
