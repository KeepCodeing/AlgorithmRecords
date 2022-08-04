#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;
const int M = 30, K = M * 2, INF = 0x3fffffff;
int graph[M][M];
int val[M];
int T;
int head[M], e[K], ex[K], w[K], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}

int ans = 0;
vector<int > path, rpath;
int dfs(int st, vector<int >& path, int stat, int sval) {
	if (stat == -1) {
		int temp = 0;
		for (int j = 0; j < path.size() - 1; j++) temp += val[path[j]];
		
		if (temp > ans) {
			ans = temp;
			rpath = path;
		}
		
		return -1;
	}
	
	for (int i = head[st];; i = ex[i]) {
		path.push_back(e[i]);
		int res = dfs(e[i], path, i, sval);
		path.pop_back(); 
		if (res == -1) return 0;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> T;
	memset(head, -1, sizeof head);
	for (int i = 1; i <= T; i++) cin >> val[i];
	
	int ut;
	for (int i = 1; i <= T - 1; i++) {
		for (int j = i + 1; j <= T; j++) {
			cin >> ut;
			if (!ut) continue;
			add(i, j, val[j]);
		}
	} 
	
	for (int i = 1; i <= T; i++) {
		path.push_back(i); 
		dfs(i, path, 0, val[i]);
		path.clear();
	}
	for (int i = 0; i < rpath.size() - 1; i++) cout << rpath[i] << ' ';
	cout << endl;
	cout << ans;
	return 0;
}
