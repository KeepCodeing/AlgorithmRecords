#include <iostream>
#include <vector>
using namespace std;

// ϲ���ּ���������DP...
// ����ߵĵط�һ����(m - 1, n)����(m, n - 1)
// ��̬ת�Ʒ��̾���f(m, n) = max{f(m - 1, n), f(m, n - 1)}
// ���һ����ѡ���߽��ֻ�����ϸ���ת�ƶ��� 

// ģ����w���ڶ���һ��AC���⣬���챻LeetCode��ĥ����... 

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
