#include <iostream>
#include <vector>
using namespace std;
int n, k;
int cnt = 0;
void dfs(int level, int deepth, int sNum, int used/*, vector<int > path*/) {
	// 剪枝 
	if (used > k) return;
	if (used == k && sNum == n) {
		if (sNum == n) {
			cnt++;
//			for (int i = 0; i < path.size(); i++) cout << path[i] << ' ';
//			cout << endl;
		}
		return;
	}
	for (int i = level; i <= deepth; i++) {
		if (sNum + i > n) continue;
		// path.push_back(i); 
		// 因为这里设置的是单调上升或者不变的情况，所以无需考虑重复 
		dfs(i, deepth, sNum + i, used + 1/*, path*/);
		// path.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	//vector<int > path;
	dfs(1, n, 0, 0/*, path*/);
	cout << cnt;
	return 0;
}
