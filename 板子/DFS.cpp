#include <iostream>
#include <vector>
#define endl '\n'
#define x first
#define y second
using namespace std;

// https://www.luogu.com.cn/problem/P1238

const int N = 20;
typedef pair<int, int > PII;
int m, n;
bool mp[N][N], vis[N][N];
vector<vector<PII > > vec;
int sx, sy, ex, ey;
void dfs(int x, int y, vector<PII >& path) {
	if (x < 1 || x > m || y < 1 || y > n) return;
	if (vis[x][y]) return;
	if (!mp[x][y]) return;
	
	if (x == ex && y == ey) {
		path.push_back(PII(ex, ey));
		vec.push_back(path); 
		return;
	}
	
	vis[x][y] = true;
	path.push_back(PII(x, y)); 
	
	dfs(x, y - 1, path);
	dfs(x - 1, y, path);
	dfs(x, y + 1, path);
	dfs(x + 1, y, path);
	
	vis[x][y] = false;
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	vector<PII > temp;
	dfs(sx, sy, temp);
	if (!vec.size()) {
		cout << "-1" << endl;
		return 0;
	} 
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << '(' << vec[i][j].x << ',' << vec[i][j].y << ')';
			if (j != vec[i].size() - 1) cout << "->";
		}
		cout << endl;
	}
	return 0;
}
