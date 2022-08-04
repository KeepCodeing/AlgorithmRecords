#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// ������������������������·���¾��������.. ������Ϊ��ȨȫΪ1
// ������ʵ���Բ��þ������顣���������ȨȫΨһ����ô�ǲ��ǿ�����BFS
// �󣬲�̫��������ܣ���BFS����û��ô����ͼ�ϣ���������̫�ᣩ... 

// ����pairҲ�Ǳ���ģ���Ȼֻ��Ե�һ��Ԫ�صı�ȨΪ0���ԣ�����û��������
// ���ǲ�ϰ��w 

typedef pair<int, int > PII;
const int N = 1e5 + 10, M = N * 2 + 10, INF = 0x3fffffff;
int head[N], e[M], ex[M], idx = 0;
int dist[M];
bool visited[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int d, int n) {
	fill(dist, dist + M, INF);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0; 
	int res = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > 1 + wt) {
				dist[vt] = 1 + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}	
	for (int i = 2; i <= n; i++) {
		//printf("%d ", dist[i]);
		res += (int)(dist[i] <= d);
	}
	return res;
}
int main() {
	int n, d, ut, vt;
	fill(head, head + N, -1);
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	printf("%d", dijkstra(1, d, n));
	return 0;
}
