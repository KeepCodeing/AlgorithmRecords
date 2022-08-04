#include <iostream>
#include <cstring>
using namespace std;

// 试下拓扑图跑最长路是不是真能搞到最优解什么的 
// 坠毁... 

typedef pair<int, int > PII;
const int N = 50000 + 10;
int head[N], e[N], ex[N], w[N], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int cost[N];
int d[N];
int dp(int i) {
	if (d[i] > 0) return d[i];
	d[i] = 1;
	for (int j = head[i]; j != -1; j = ex[j]) {
		int vt = e[j];
		d[i] = max(d[i], dp(vt) + w[j]);
	}
	return d[i];
}
int main() {
	memset(head, -1, sizeof head);
	int n, fee, wt;
	cin >> n >> fee;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) add(i, j, cost[j] - cost[i] - fee);
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = head[i]; j != -1; j = ex[j]) {
//			int vt = e[j];
//			cout << i << ' ' << vt << ' ' << w[j] << endl;
//		}
//	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(d, 0, sizeof d), res = max(res, dp(i));
		for (int j = 1; j <= n; j++) cout << d[j] << ' ';
		cout << endl;
	}
	cout << res << endl;
	return 0;
}
//6 2
//1 2 3 8 4 9
