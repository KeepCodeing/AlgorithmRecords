#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 同样想不到状态转移方程，但是可以写个爆搜试试 

const int N = 45, M = 800;
int f[N][M];
int cnt = 0;
int n;
vector<int > vec;
int dfs(int level, int deepth, int sNum) {
	if (sNum > deepth - sNum) return 1;
	if (level == n) {
		if ((deepth - sNum) == sNum) {
//			for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
//			cout << endl;
			cnt++;
		}
		return 1;
	}
	//if (f[level][sNum] != -1) return f[level][sNum];
	vec.push_back(level); 
	f[level][sNum] = dfs(level + 1, deepth, sNum + level);
	vec.pop_back();
	f[level][sNum] = dfs(level + 1, deepth, sNum);
} 
int main() {
	memset(f, -1, sizeof f);
	cin >> n;
	int t = 0;
	for (int i = 1; i <= n; i++) t += i;
	dfs(1, t, 0);
	cout << cnt;
	return 0;
}
