#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

// 题意都没看明白...这个题的意思就是给N次输入，每次输入K个点，其中第i个点和K == 0时的
// 那个点直接相连（边权为0），后面所有点间接相连（边权为1），然后求最短路... 

// 查了半天错，最后还是找到了...原来是空间开小了w，不过查的时候就一直在想是不是这个问题，因为之前也被坑过...
// 还是题目没读懂，输入N组数据，每组数据K个，也就是最多有100 * 100的数据，而不是就100个... 

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
			// 第一个点直接相连，边权为0，后面的点边权为1，注意这里不能省去w数组，因为
			// 边权不止一种情况.. 
			if (j == 1) add(i, vt, 0);
			else add(i, vt, 1);
		}
	}
	printf("%d", dijkstra(s, t));
	return 0;
}
