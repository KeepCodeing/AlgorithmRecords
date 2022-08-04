#include <iostream>
#include <vector>
using namespace std;

// 喜闻乐见的坐标型DP...
// 最后走的地方一定是(m - 1, n)或者(m, n - 1)
// 动态转移方程就是f(m, n) = max{f(m - 1, n), f(m, n - 1)}
// 起点一样必选，边界点只能由上个点转移而来 

// 模板题w，第二个一次AC的题，今天被LeetCode折磨惨了... 

class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
		int m = grid.size(), n = grid[0].size();
		int f[m + 10][n + 10];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) {
					f[i][j] = grid[i][j];
				} else {
					f[i][j] = 0;
					if (i == 0 || j == 0) {
						if (i == 0) f[i][j] = f[i][j - 1] + grid[i][j];
						else f[i][j] = f[i - 1][j] + grid[i][j];
					} else {
						f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i][j];
					}
				}
			}
		}
		return f[m - 1][n - 1];
    }
};

int main() {
	return 0;
}
