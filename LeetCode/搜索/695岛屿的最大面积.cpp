#include <iostream>
#include <vector>
using namespace std;
// 分析：漫水填充法填充每个子图，然后更新最大面积，注意这里没有用visited存放已经访问过的
// 点，因为所有子图都只用访问一次统计面积，所以访问了可以直接将该点变为0，而程序只对1进行
// 访问，所以相当于标记了被访问点。

// 这题和书上的漫水填充法有所不同，它不要求输出填充后的子图，所以不需要填色，而上述标记为0
// 的做法也和visited标记不同 
class Solution {
public:
	int line, column;
	vector<vector<int> > m;
	int dfs(int x, int y) {
		// 出界判断 
		if (x >= line || x < 0 || y >= column || y < 0) return 0;
		// 访问过判断以及是否是水判断 
		if (m[x][y] != 1) return 0; 
		// 评论看到的，将已经访问过的点标记为0，这样也可以避免重复访问，同时
		// 方便了调用时的判断 
		m[x][y] = 0; 
		// 增加面积 		
		int sum = 1;
		sum += dfs(x + 1, y);
		sum += dfs(x - 1, y);
		sum += dfs(x, y + 1);
		sum += dfs(x, y - 1);
		return sum;
	}
    int maxAreaOfIsland(vector<vector<int> >& grid) {
    	if (grid.size() <= 0 || grid.empty()) return 0;
        this->line = grid.size();
        this->column = grid[0].size();
        this->m = grid;
        int maxSize = 0;
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->column; j++) {
        		// 对子图开始填充 
        		if (m[i][j] != 0) {
        			maxSize = max(dfs(i, j), maxSize);
				}
			}
		}
        return maxSize;
    }
}; 
int main() {
	return 0;
}
