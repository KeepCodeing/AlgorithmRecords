#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 判断正环，注意这里给的是有向图，但是是个完全有向图，那么当成无向图开空间处理就行.. 
// 大耳和功放到了... 

const int N = 100 + 10, M = 100 * 2 + 10;
int head[N], e[M], ex[M], idx = 0;
double hl[M], yj[M];
bool visited[N];
double dist[N];
void add(int ut, int vt, double hlt, double yjt) {
	e[idx] = vt, hl[idx] = hlt, yj[idx] = yjt, ex[idx] = head[ut], head[ut] = idx++;
}
string spfa(int st, double money) {
	memset(dist, 0, sizeof dist);
	queue<int > que;
	que.push(st);
	// 一下子忘了怎么搞到手上现在拿的是多少钱..还是看了以前的代码才记起来原来就是dist..，所以初始
	// 化一开始也是错的w... 
	dist[st] = money;
	while (que.size()) {
		int ut = que.front();que.pop();
		if (ut == st && dist[ut] > money) return "YES";
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			double cost = (dist[ut] - yj[i]) * hl[i];
			if (dist[vt] < cost) {
				dist[vt] = cost;
				if (!visited[vt]) {
					visited[vt] = true;
					que.push(vt); 
				}
			}
		}
	}
	return "NO";
}
int main() {
	int n, m, s, ut, vt;
	double val, hl1, yj1, hl2, yj2;
	memset(head, -1, sizeof head);
	scanf("%d%d%d%lf", &n, &m, &s, &val);
	while (m--) {
		scanf("%d%d%lf%lf%lf%lf", &ut, &vt, &hl1, &yj1, &hl2, &yj2);
		add(ut, vt, hl1, yj1);
		add(vt, ut, hl2, yj2);
	}
	cout << spfa(s, val);
	return 0;
}
