// 打卡题，这里写边缘判断时有点迟疑，主要是没有搞清楚状态，对于边缘的点而言，它们的状态只能是上一个点转移而来，
// 而上一个点有哪些情况呢？无非是一种走法，或者零种走法，注意：f[i][j]表示的是(i, j)能有多少种走法，而不是这个
// 点走了多少步，也就是不能用f[i][j] = f[i - 1][j] + 1之类的方法来转移状态... 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int f[110][110];
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            	// 注意这里的坑爹判断，出口也可能是障碍，所以得先判断是否是障碍... 
                if (obstacleGrid[i][j]) f[i][j] = 0;
                else if (i == 0 && j == 0) f[i][j] = 1;
                else if (i == 0 && j != 0) f[i][j] = f[i][j - 1];
                else if (j == 0 && i != 0) f[i][j] = f[i - 1][j];
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[n - 1][m - 1];
    }
};
