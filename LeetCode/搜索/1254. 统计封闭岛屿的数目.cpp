#include <iostream>
#include <vector>
using namespace std;

// 洛谷里的题解的思路是多加一圈，这样的话就可以自然而然的把所有陆地都标记到，但是这样容易
// 导致数组出界，而且对LeetCode的直接给出数据的情况并不适用。
// LeetCode的题解的思路则是用一个变量标记是否出界，由题目我们可以推断出但凡是封闭的岛屿对其
// 进行遍历都不会出现出界的情况，所以我们可以对所有陆地进行遍历，如果这个陆地被水包围了，那么
// 不管怎么遍历都不会出到水外，而如果这个陆地没有被水包围，则绝对会出到地图之外 

// 两个坑：
// 1. 局部变量名和成员变量名相同且没有区分开来
// 2. flag的值没有通过&改变 

class Solution {
public:
	int line, col;
	vector<vector<int> > g;
	// 注意这里的& 
	void dfs(int x, int y, bool& flag) {
		if (x >= line || x < 0 || y < 0 || y >= col) {
			// 出界即说明不是封闭岛屿 
			flag = false;
			return;
		}
		if (g[x][y] != 0) return;
		// 染色以及遍历
		g[x][y] = 1;
		dfs(x + 1, y, flag);
		dfs(x - 1, y, flag);
		dfs(x, y + 1, flag);
		dfs(x, y - 1, flag);
	}
    int closedIsland(vector<vector<int> >& grid) {
    	bool flag;
    	int ans = 0;
    	// 被相同的变量名坑了，成员变量和局部变量不一样的... 
    	this->g = grid;
        this->line = grid.size(), this->col = grid[0].size();
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->col; j++) {
        		// 只对陆地进行DFS
        		if (g[i][j] != 1) {
        			flag = true;
        			// flag之前只是传进去了，没有加&改变其值 
        			dfs(i, j, flag);
        			if (flag) ans++;
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
}
