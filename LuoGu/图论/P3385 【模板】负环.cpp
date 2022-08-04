#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ��������д�涴�Ǹ���ģ������������ﻹ�и�ģ���⣬�Ǿ���д�����...д����Ϣ...�����ܿ���w...

// ��֪���߶��٣���Ҳ���ܳ������Կ��ܴ�... 
const int N = 2 * 1e4, M = 1e6 * 2;
// 33 39
// �ĸ�����Ҫ��γ�ʼ����head��dist��visited��cnt������idx����... 
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N], cnt[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int T, n, m, ut, vt, wt;
bool spfa(int st) {
	memset(visited, 0, sizeof visited);
	memset(dist, 0x3f, sizeof dist);
	// ���������cnt����ĳ�ʼ��
	memset(cnt, 0, sizeof cnt); 
	queue<int > que;
	que.push(st);
	dist[st] = 0;
	cnt[st] = 1;
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				// ����Ӧ����visited[vt]������ut�����ü����w 
				if (!visited[vt]) {
					visited[vt] = true, cnt[vt]++;
					if (cnt[vt] >= n) return true;
					que.push(vt); 
				}
			}
		}
	} 
	return false;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head);
		// idx���˳�ʼ��... 
		idx = 0;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			// С��0����ߣ�����˫��� 
			if (wt < 0) add(ut, vt, wt);
			else add(ut, vt, wt), add(vt, ut, wt);
		}
		bool res = spfa(1);
		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}
