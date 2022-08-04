#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;

// https://www.luogu.com.cn/problem/P1339

const int N = 2500 + 10, M = N * 2;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}

int dist[N], cnt[N];
bool vis[N];
int n, m, s, t, ut, vt, wt;

int spfa(int st, int ed) {
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front(); que.pop();
		vis[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!vis[vt]) {
					// 判断是否存在负环 
//					cnt[vt]++;
//					if (cnt[vt] >= n) {
//						cout << "存在负环" << endl;
//						return;
//					}
					vis[vt] = true;
					que.push(vt);
				} 
			}
		}
	} 
	return dist[ed];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(head, -1, sizeof head);
	cin >> n >> m >> s >> t;
	while (m--) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt);
		add(vt, ut, wt);
	}
	cout << spfa(s, t);
	return 0;
}
