#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 不知道虚拟源点能不能解决，总之先给所有喜欢的牧场加上0点，然后跑公共最短路，然后统计下那个点
// 的值最小... 
// 然而虚拟源点没有什么用，写了个n^2logn的多次Dijkstra，超时了... 
// 数据类型又写错了，明明写的除用的却是int...然后开O2苟过去了，看下不开能不能过..原来过的那发
// 本来就没开O2...其实一个题交5次有悖其尽量拉高通过率的初心..不过没办法呢，程序总是出现蜜汁错误... 

typedef pair<int, int > PII;
const int N = 510, M = 8000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
int visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
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
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
vector<int > fov;
int main() {
	memset(head, -1, sizeof head);
	int p, f, c;
	scanf("%d%d%d", &p, &f, &c);
	int ft;
	for (int i = 0; i < f; i++) {
		scanf("%d", &ft);
		fov.push_back(ft); 
	}
	int ut, vt, wt;
	for (int i = 0; i < c; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// 这里居然能写成add(ut, vt, wt), (vt, ut, wt);...
		add(ut, vt, wt), add(vt, ut, wt);
	}
	double minPath = 1e9;
	double temp;
	int fLen = fov.size(), res;
	for (int i = 1; i <= p; i++) {
		dijkstra(i), temp = .0;
		for (int j = 0; j < fLen; j++) temp += dist[fov[j]];
		// 这里居然又写错了数据类型，最幸福的人... 
		temp /= .0 + f;
		if (minPath > temp) {
			minPath = temp;
			res = i;
		}
	}
	printf("%d", res);
	return 0;
}

