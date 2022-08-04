#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// SPFA���·������˵���ǽ��ɳڵ����������£��Ӵ��ڱ��С��...
// ֮ǰ��Dijkstra����������׹����w����Ȼ�и�Ȩ�߻�����SPFA�ȽϺ�...������Ҳ�е�С���⣬
// ����������и������߼����ƺ������Ĵ��ڻᵼ�²��������·������ȴ���·û��Ӱ�죬��Ϊ
// ����Ҫ���Ǳ�Ȩ���ϱ�󣬶����ǲ��ϱ�С... 

// ����ͼ 
const int N = 1500 + 10, M = 5 * 1e4 + 10, INF = -0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m, ut, vt, wt;
int spfa(int st) {
	queue<int > que;
	for (int i = 0; i < N; i++) dist[i] = INF, visited[i] = false;
	que.push(st);
	// ע���ʼ����� 
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front();que.pop();
		// SPFA��ÿ�����ӵĽڵ���Ϊδ���ʣ������Dijkstra�����е������ 
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// �ɳ��������¾�����..ע���Dijkstra������Dijkstra����ͨ��dist[ut]����ȡ��Ȩ�ģ�����ͨ��
			// pair����������� 
			if (dist[vt] < dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				// û���ù���ѭ����� 
				if (!visited[vt]) {
					visited[vt] = true;
					que.push(vt); 
				}
			}
		}
	}
	// �����в���ͨ����� 
	if (dist[n] == INF) return -1;
	return dist[n];
}
int main() {
	// �����˳�ʼ��ͷͷ���w 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	printf("%d", spfa(1));
	return 0;
}
