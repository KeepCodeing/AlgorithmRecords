#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

// 这个题就是不同路径的变种，我们可以在原有的状态转移方程上进行修改
// 首先考虑有障碍的情况，对于有障碍的点，走到那里的方案数是不存在的，也就是0， 
// 那么对于可以走的点呢，可以发现依然是除了边界上的那些点只有一种方式走到其它点
// 都有两种方式走到.. 
// 但是，我们要注意到，对于边界上的点，我们默认是都有一种走法的，那么假设处于边界
// 上的某个点是障碍，对于它之后的所有点又有多少种走法呢？很明显是0种，因为边界点
// 只能朝着一个方向走，如果这个路径上有个点被堵住了，后面的点按道理来说应该都做不了了.. 
// 所以得加些判断.. 
// 然而这样写坠毁了...  

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int f[110][110];
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (obstacleGrid[i][j]) {
        			// 如果走不了，那就只有0种走法 
        			f[i][j] = 0;
				} else {
					// 起点一定有一种走法 
					if (i == 0 && j == 0) f[i][j] = 1;
					else {
						// 先将每个点的走法置为0，这样可以包括上一个点走不了的情况 
					    f[i][j] = 0;
					    // 如果能从上一个点走过来，那么当前的走法就是上一个点的走法之和 
				        if (i - 1 >= 0) f[i][j] += f[i - 1][j];
					    if (j - 1 >= 0) f[i][j] += f[i][j - 1];
					}
					
				}
			}
		}
		return f[m - 1][n - 1];
    }
};

int main() {
	int a[10]={34,87,23,15,32,46,67,62,28,30};
	sort(a, a + 10);
	for (int i = 0; i < 10; i++) cout << a[i] << ' ';
	return 0;
}
