#include <iostream>
#include <vector>
using namespace std;

// 加了个约束条件，就是所有非障碍空格都得走一遍，那么我们可以记录所有
// 可走方格的数量，然后在到达终点时判断是否都走过 

class Solution {
public:
	int line, col;
	int ans;
	vector<vector<int> > g;
	void dfs(int sx, int sy, int ex, int ey, int zeroCnt) {
		if (sx < 0 || sx >= line || sy < 0 || sy >= col) return;
		if (g[sx][sy] == -1) return;
		int temp = g[sx][sy];
		// 这里起点也算进0里了，所以要减去-1 
		if (temp == 2 && zeroCnt == -1) {
			ans++;
			return;
		}
		g[sx][sy] = -1;
		dfs(sx + 1, sy, ex, ey, zeroCnt - 1);
		dfs(sx - 1, sy, ex, ey, zeroCnt - 1);
		dfs(sx, sy + 1, ex, ey, zeroCnt - 1);
		dfs(sx, sy - 1, ex, ey, zeroCnt - 1);
		g[sx][sy] = temp;
	}
    int uniquePathsIII(vector<vector<int> >& grid) {
    	int start_x, start_y, end_x, end_y;
    	int zeroCnt = 0;
    	this->ans = 0;
		this->line = grid.size();
		this->col = grid[0].size();
		this->g = grid;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (g[i][j] == 0) zeroCnt++;
				if (g[i][j] == 1) start_x = i, start_y = j;
				if (g[i][j] == 2) end_x = i, end_y = j;
			}
		}
		dfs(start_x, start_y, end_x, end_y, zeroCnt);
		return ans;
    }
};

int main() {
	return 0;
}
