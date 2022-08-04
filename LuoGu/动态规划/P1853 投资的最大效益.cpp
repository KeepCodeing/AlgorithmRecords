#include <iostream>
#define endl '\n'
using namespace std;

const int N = 40 + 10, M = 10 + 10;

int pay[N], money[M];
int f

int dfs(int s, int year, int i) {
	
	if (s < 0) return 0;
	if (year < 0) return 0;
	
	// 当前本金/剩余年数/选择第几号债券 
	
	dfs(s - pay[i], year - 1, i) + money[i];
	dfs(s, year - 1, i + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int s, n, d;
	cin >> s >> n >> d;
	for (int i = 1; i <= d; i++) cin >> pay[i] >> money[i];
	
	return 0;
}

int dfs(int s, int e) {
	
	if (f[s][e]) return f[s][e];
	
	if (s > e) return 0;
	
	int ans = -9999999;
	for (int i = s; i <= e; i++) {
		if (i == s) ans = max(ans, dfs(i + 1, e) + nums[i]);
		else ans = max(ans, dfs(i + 1, e) + abs(nums[i] - nums[s]) * (i - s + 1));
		
		if (i == e) ans = max(ans, dfs(s, i - 1) + nums[i]);
		else ans = max(ans, dfs(s, i - 1) + abs(nums[i] - nums[e]) * (e - i + 1));
	}
	
	return f[s][e] = ans;
}
