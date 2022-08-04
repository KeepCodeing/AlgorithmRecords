#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 本来打算写虫洞那个题的，不过发现这里还有个模板题，那就先写这个了...写完休息...下下周考试w...

// 不知道边多少，点也可能超，所以开很大... 
const int N = 2 * 1e4, M = 1e6 * 2;
// 33 39
// 四个数组要多次初始化，head，dist，visited，cnt，还有idx变量... 
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
	// 差点又忘了cnt数组的初始化
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
				// 这里应该是visited[vt]，不是ut，还好检查了w 
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
		// idx忘了初始化... 
		idx = 0;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			// 小于0单向边，否则双向边 
			if (wt < 0) add(ut, vt, wt);
			else add(ut, vt, wt), add(vt, ut, wt);
		}
		bool res = spfa(1);
		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}
