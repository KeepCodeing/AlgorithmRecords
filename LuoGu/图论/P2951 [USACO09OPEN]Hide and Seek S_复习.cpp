#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ���·��ϰ���ĵ�����ô�������Ǵ�1��һ�����·��Ȼ�����·�ı�ţ�����...
// ˼�����ܲ�������С�������������ǲ��У���Ϊ��С�����������ع�������ͼ���������Ļ��µĵ���ͼ��һ������1Ϊ���ģ�����
// ����Ҳ�޷�ͳ�ƴ�1������������·�ĸ��������ȵ�... 

// ȥע�͸�CE��..�����˺þ�֮ǰд�Ĵ����ˣ������õ�vector����ʱ��д�ıȽϸ��ӣ�Ҳ�ѹָ㲻����w 

typedef pair<int, int > PII;
const int N = 20000 + 500, M = 50000 * 5 + 100;
int head[N], e[M], ex[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// ע�������Ϊ��Ȩʼ��Ϊ1����˿���ʡȥһ��w���飬����pair���ﲻ��ʡ����Ϊ��һ���㵽�Լ��ı�Ȩʱ����Ϊ0�� 
			if (dist[vt] > wt + 1) {
				dist[vt] = wt + 1;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
int main() {
	int n, m;
	// ���ǳ�ʼ��ֻ��TLEw 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	int ut, vt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	dijkstra(1);
	int id = -1, ds = 0, cnt = 1;
	// ��Ϊ�³���������ͳ�������ֵ��Ȼ���ٸ��´𰸣����ܣ� 
	for (int i = 1; i <= n; i++) ds = max(dist[i], ds);
	for (int i = 1; i <= n; i++) {
		// ��¼��һ�����ֵ���Լ�ͳ�������ĵ�ĸ���... 
		if (dist[i] == ds && id == -1) id = i; 
		else if (dist[i] == ds) cnt++;
	}
	printf("%d %d %d", id, ds, cnt);
	return 0;
}
