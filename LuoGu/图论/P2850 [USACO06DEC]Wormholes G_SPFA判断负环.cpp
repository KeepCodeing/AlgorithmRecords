#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;

// 做过的题了..不知道为什么CE了发w.. 

const int N = 500 + 10, M = 6000;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N], cnt[N];
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
string spfa(int st, int n) {
	memset(dist, -1, sizeof dist);
	memset(vis, 0, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	queue<int > que;
	que.push(st);
	dist[st] = 0; 
	while (que.size()) {
		int ut = que.front(); que.pop();
		vis[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!vis[vt]) {
					cnt[vt]++;
					if (cnt[vt] >= n) return "YES";
					vis[vt] = true;
					que.push(vt); 
				}
			}
		}
	}
	return "NO";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T, n, m, wo, ut, vt, wt;
	cin >> T;
	while (T--) {
		bool flag = false;
		memset(head, -1, sizeof head), idx = 0;
		cin >> n >> m >> wo;
		while (m--) {
			cin >> ut >> vt >> wt;
			add(ut, vt, wt);
			add(vt, ut, wt);
		}
		while (wo--) {
			cin >> ut >> vt >> wt;
			add(ut, vt, -wt);
		}
		// 没给起点的题一律每个点都跑次，而且从数据范围来看这样
		// 也是允许的.. 
		for (int i = 1; i <= n; i++) {
			if (spfa(i, n) == "YES") {
				flag = true;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
