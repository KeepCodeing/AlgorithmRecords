#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
int rd[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m, ut, vt;
void bfs() {
	queue<int > que;
	for (int i = 1; i <= n; i++) {
		if (!rd[i]) que.push(i); 
	}
	while (que.size()) {
		int ut = que.front(); que.pop();
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			rd[vt]--;
			if (!rd[vt]) que.push(vt); 
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(head, -1, sizeof head);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> ut >> vt;
		add(ut, vt);
		rd[vt]++;
	}
	
	return 0;
}
