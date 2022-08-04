// 找到了比较心仪的写法，就是模拟DFS，记得迫真模拟赛没写出来直接copy的ww，这里题可以模拟DFS，但是也有些要注意的地方... 
class Solution {
public:
	// 首先是走的方向顺序，应该是右->下->左->上 
    int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int > res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return res;
        int n = matrix.size(), m = matrix[0].size();
        // 因为第一个点坐标为0,0，但是按照我们走的顺序来的话就不会走到，因此要把第一个点的横坐标设置为-1（这里
		// 变量不代表坐标轴） 
		int cur = 0, cx = 0, cy = -1, cnt = 0;
        while (cnt < m * n) {
            int nx = cx + mv[cur][0], ny = cy + mv[cur][1];
            // 这里是判断是否在界内，如果在界内就走，不在界内就换个方向走 
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != INT_MAX) {
                cnt++;
                // 下一步就是在这一步的基础上来的 
                cx = nx, cy = ny;
                res.push_back(matrix[nx][ny]);
                // 将走过的地方标记 
                matrix[nx][ny] = INT_MAX;
                // 如果走出界了，换个方向，这里%4是保证数组不出界 
            } else cur = (cur + 1) % 4;
        }
        return res;
    }
};
