#include <iostream>
#include <vector>
using namespace std;

// 这是道坐标DP
// 根据之前的经验，可以得到这个题的最后一步是走到了(m - 1, n)或者(m, n - 1)这两个点，那么子问题就是
// 从(0,0)点出发，使f(m - 1, n) + f(m, n - 1)最小。
// 于是可得状态转移方程，设f(m, n)=从(0,0)走到(m, n)点的路径上的数字之和最小。那么f[m][n] = min{f[m - 1][n], f[m][n - 1]};
// 考虑初始值，因为是从(0, 0)点出发，所以这个点上的值是必选的，边界就是不出地图。
// 另外起点和边界点的赋值也和普通点的赋值不一样...，起点的赋值是在循环里进行的，这点比较重要，如果直接在外面赋值，会导致
// 第一次走是向下还是向左走的疑惑。而边界点的赋值就比较特殊了，由于边界点只能由上一个边界点走到，所以其实边界点不满足我们
// 的状态转移方程，也就是不存在选或不选，只有选的情况。而如果只能选的话，那么当前点的最优解其实就是上一个点的最优解加上
// 这个位置的数字的和...还有就是每个点的初始值设置，我们默认让每个点都不选任何数，那么这个点的最优解在选数之前就是0 

// 啊啊，这算是其第一道自己推方程AC的DP题了w，虽然是套模板... 
 
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size();
        int f[m + 10][n + 10];
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		// 起点的特殊初始化 
        		if (i == 0 && j == 0) {
        			f[i][j] = grid[i][j];
				} else {
					// 初始化最优解，即不选任何数的值 
					f[i][j] = 0;
					// 边界点比较特殊，只能选 
					if (i == 0 || j == 0) {
						// 任意一个边界点的最优解都是由上一个边界点转移而来 
						if (i == 0) f[i][j] = f[i][j - 1] + grid[i][j];
						else f[i][j] = f[i - 1][j] + grid[i][j];
					} else {
						// 如果是普通点，那么最优解就满足我们的状态转移方程，即要使f[m][n]和最小，一定要保证
						// 我们取的上一个点的值是min{f[m - 1][n], f[m][n - 1]} 
						f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
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
