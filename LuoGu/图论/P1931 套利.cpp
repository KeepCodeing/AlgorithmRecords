#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

// 又是一道做过的题w...相比之前两道好久之前做的题应该会更有印象吧... 
// 险些忘记...事实证明就算会了不打也会忘，更何况即甚至不会呢... 

const int N = 1000;
int head[N], e[N], ex[N], idx = 0;
double w[N], dist[N];
bool vis[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
map<string, int > mp;
bool spfa(int st) {
	for (int i = 0; i < N; i++) dist[i] = 0;
	memset(vis, 0, sizeof vis);
	queue<int > que;
	que.push(st);
	dist[st] = 1.0;
	while (que.size()) {
		int ut = que.front(); que.pop();
		vis[ut] = false;
		if (ut == st && dist[st] > 1.0) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			double wt = w[i] * dist[ut];
			// 凭着记忆里的板子一通乱打，然后发现不对...检查了才发现是松弛条件错了，应该是越变越大才行，而不是
			// 和最短路一样变小，因为套利就是为了赚钱... 
			// 看了下题目说是求最长路，可能这里松弛条件是，但是本质还是判断“正环”的... 
			if (dist[vt] < wt) {
				dist[vt] = wt;
				if (!vis[vt]) {
					vis[vt] = true;
					que.push(vt); 
				}
			}
		}
	} 
	return false;
}
int main() {
	int n, m;
	double wt;
	string ut, vt;
	for (int T = 1; cin >> n, n; T++) {
		bool flag = false;
		// 注意邻接表的初始化idx也要恢复 
		memset(head, -1, sizeof head), idx = 0;
		for (int i = 1; i <= n; i++) cin >> ut, mp[ut] = i;
		cin >> m;
		while (m--) {
			cin >> ut >> wt >> vt;
			add(mp[ut], mp[vt], wt);
		}
		for (int i = 1; i <= n; i++) {
			if (spfa(i)) {
				flag = true;
				break;
			}
		}
		cout << "Case " << T << ": " << (flag ? "Yes" : "No") << '\n';
	}
	return 0;
}
