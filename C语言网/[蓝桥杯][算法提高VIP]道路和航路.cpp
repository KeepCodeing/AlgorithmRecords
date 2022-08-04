#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

// ����û�����w�����ŷ��򽨱�����..ʵ���ϲ��ܷ��򽨱ߣ����ж���㵽һ�����ʱ��
// ���Է��򽨱ߣ�����Ͳ��ܣ��������ʵ�ƺ����ĵ��������У��������������е�����.. 
// ������Կ����������᲻���и��������ȿ���ȷ���и�Ȩ�ߣ�������Dijkstra����������
// ���ڸ���ô..Ӧ����û�еģ��и����Ļ����·�����ڣ�����Ҳû�취�жϺ���ĵ��ܲ��ܵ�.. 

// ��֪����Ϊʲô���ԭ��TLE��... 

const int N = 150000 + 10, M = N * 2 + 10, INF = 0x3f3f3f3f;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N], cnt[N];
int n, r, p, s, ut, vt, wt;
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void spfa(int st) {
	queue<int > que;
	que.push(st);
	// �ֳ�����w���ѳ�ʼ��д��������ʼ��֮��... 
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front();que.pop();
		vis[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!vis[vt]) {
					cnt[vt]++;
					if (cnt[vt] >= n) return;
					vis[vt] = true;
					que.push(vt);
				}
			}
		}
	}
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d%d%d%d", &n, &r, &p, &s);
	// ��˫��� 
	for (int i = 0; i < r; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		add(vt, ut, wt);
	}
	// �������
	for (int i = 0; i < p; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	} 
	spfa(s);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) printf("NO PATH");
		else printf("%d", dist[i]);
		puts("");
	}
	return 0;
}
