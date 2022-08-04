#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 10;
int nums[N][N], maxRes; 
int T, n, m;
bool vis[N][N];
int mv[18][2] = {{2, 2}, {-2, -2}, {2, -2}, {-2 ,2}, {2, 0}, {-2, 0}, {0, 2}, {0, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int t[8][2] = {};
vector<PII > path;
void dfs(int x, int y, int res) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i].first << ' ' << path[i].second << endl;
		}
		cout << "----------------" << endl;
		return;	
	}
	if (vis[x][y]) return;
	vis[x][y] = true;
	// ncout << res << endl;
	for (int i = 0; i < 16; i++) {
		int nx = x + mv[i][0], ny = y + mv[i][1];
		// if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		path.push_back(PII(nx, ny)); 
		dfs(nx, ny, res + nums[x][y]);
		path.pop_back();
	}
	// vis[x][y] = false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cin >> nums[i][j];
		}
		dfs(0, 0, 0);
		
	}
	
	return 0;
}
