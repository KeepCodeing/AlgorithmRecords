#include <iostream>
#include <cmath>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 1000 + 10;
typedef long long LL;

LL ct[N], we[N];
LL f[N][N];

// 求的是最小的疲劳值，而不是最少要花的天数

int n, m;
LL dfs(int i, int d) {
	
	if (f[i][d] != -1) return f[i][d];
	
	// 所有城市走完了，这里本来写的>n，但因为i从0开始所以n其实就是终点了... 
	if (i == n) return 0;
	
	// 所有时间都花完了，注意这里极值的设置，之前设置小了（比如999999）导致极值比答案还小最后返回的极值... 
	// 注意这里题解写的m + 1，可能和i == n的判断位置有关... 
	if (d > m) return 1e9;
	 
	// d-1天走到i + 1这个城市  在第i个城市休息，注意这里的i + 1，因为i从0开始而且题目说的花费
	// 是i-1城市移动到i城市在第j天进发时的花费 
	return f[i][d] = min(dfs(i + 1, d + 1) + ct[i + 1] * we[d], dfs(i, d + 1));

} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ct[i];
	for (int i = 1; i <= m; i++) cin >> we[i];
	memset(f, -1, sizeof f);
	// 这个题是从0点开始走起，然后花费是起点+1.... 
	cout << dfs(0, 1);
	return 0;
}

