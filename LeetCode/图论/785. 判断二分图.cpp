// 因为没数据所以在LeetCode上写了判断二分图，总体来说还是踩了些坑的 
class Solution {
public:
    vector<int > grid[110];
    int color[110];
    bool dfs(int now, int c) {
        color[now] = c;
        for (int i = 0; i < grid[now].size(); i++) {
            int vt = grid[now][i];
            if (color[vt] == color[now]) return false;
            // 取反颜色，为什么这里这样写可以参考下面的解释... 
            if (!color[vt]&& !dfs(vt, -c)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // 先将图建出来
        int gLen = graph.size();
        for (int i = 0; i <gLen; i++) {
            for (auto& j : graph[i]) {
                grid[i].push_back(j);
            }
        }
        // 注意给的图可能是个森林，所以这里得写个循环枚举所有没有被染色的点，如果有一个树不是二分图，那整个森林
		// 也就不是二分图了 
        for (int i = 0; i < gLen; i++) {
        	// 利用&&的性质，当当前点没有被染色的时候，值为真，执行dfs对这个点所在的连通块染色，
			// 如果这个连通块不是二分图dfs就会返回false，然后回来取反，就会返回false... 
            if (!color[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};
