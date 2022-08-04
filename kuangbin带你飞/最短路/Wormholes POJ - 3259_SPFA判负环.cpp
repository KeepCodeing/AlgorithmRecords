#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// ���������SPFA�жϸ�����ģ������...��SPFA�жϸ�����ʵ�����ж�һ�����Ƿ���Ӷ�Σ�����ӵĴ������ڵ����˵�������
// ���Կ����¼��������һ�����n�������������������·����ʹ�������n-1�Σ���������������������ζ�Ŵ��ڸ���������
// ����̾���������ޱ���ʼ��... 
// ��������˫���Ҳ�е���ߣ�����˫��߾�������ĵ���ߣ����Խ�ͼ����Ҫ���⴦��... 

// ��Ϊ���е��������˫������Ա������Ĵ�һЩw 
const int N = 500 + 10, M = 2500 * 3 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int T, n, m, wm, ut, vt, wt;
// SPFA�жϸ���������һ�������¼ÿ�������Ӵ��� 
int dist[N], cnt[N];
bool visited[N];
bool spfa(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	// ע���Ƕ������ݣ����Ҫ��γ�ʼ��... 
	memset(cnt, 0, sizeof cnt);
	dist[st] = 0, cnt[st] = 1;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				// ������̾��� 
				dist[vt] = dist[ut] + w[i];
				if (!visited[vt]) {
					visited[vt] = true;
					// ע��ͳ�Ƶ��������ǰ�������������ˣ���û�б��ظ�����... 
					cnt[vt]++;
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
		// �������ݣ���γ�ʼ��... 
		memset(head, -1, sizeof head);
		idx = 0;
		scanf("%d%d%d", &n, &m, &wm);
		while (m--) {
			// ��˫���
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, wt), add(vt, ut, wt);
		}
		while (wm--) {
			// ������ߣ�ע�⽨�ߵı�Ȩ�Ǹ��ģ���Ϊ��Ŀ����������ν�Ļ���wt�룬��ô�����߹�ȥ�Ǻ�ʱ��
			// ����ȨΪ�������������ݾ��Ǳ�ȨΪ����... 
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, -wt); 
		}
		bool res = spfa(1);
		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}
