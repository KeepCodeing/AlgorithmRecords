#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
int graph[N][N];
bool vis[N];
int ans = 0x3fffff;
void dfs(int level, int deepth, int cost, int cnt) {
	if (level == deepth) {
		// 注意这个cnt的作用，它用来判断是否真的每一行都选了一个元素，为什么要加cnt是因为这种回溯的状态是“由上一行跳到
		// 这一行”的，至于它们中间的距离由vis[j]决定，也就是列元素是否重复... 
		if (cnt == deepth) ans = min(ans, cost);
		return;
	}
	for (int i = level; i < deepth; i++) {
		for (int j = 0; j < deepth; j++) {
			if (vis[j]) continue;
			vis[j] = true;
			dfs(i + 1, deepth, cost + graph[i][j], cnt + 1);	
			vis[j] = false;
		}
	}
}
int main () {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, n, 0, 0);
	cout << ans << endl;
	return 0;
}
