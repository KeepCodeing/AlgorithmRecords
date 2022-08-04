#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 多源BFS最短路...，这里要求的是最后一个橘子腐烂的时间，不需要打印什么的，所以可以用到LeetCode评论里的一个小技巧，
// 最后一个腐烂的橘子的点绝对就是腐烂时间最长的那个橘子，直接取坐标就能得到其时间，不需要再遍历遍距离数组 

// 看了下似乎又不行，因为还是要求所有橘子都腐烂了，这样搞可能会有橘子不腐烂，那返回的就是错的 

// WA了五次（绝望），不想再改了，LeetCode上的搜索题通过率极低... 

#define x first
#define y second
const int N = 20;
class Solution {
public:
	typedef pair<int, int > PII;
    PII que[N * N];
    int dist[N][N];
    int qtop = 0, qback = 0;
	int orangesRotting(vector<vector<int> >& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		if (grid[i][j] == 2) que[qback++] = PII(i, j), dist[i][j] = 0;
			}
		}
		return bfs(n, m, grid);
    }
    int bfs(int n, int m, vector<vector<int> >& grid) {
    	PII now;
    	int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    	while (qtop <= qback) {
    		now = que[qtop++];
    		for (int i = 0; i < 4; i++) {
    			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
    			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    			if (dist[nx][ny] != -1 || !grid[nx][ny]) continue;
    			dist[nx][ny] = dist[now.x][now.y] + 1;
    			que[++qback] = PII(nx, ny);
			}
		}
		int res = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] == -1 && grid[i][j] == 1) return -1;
				if (dist[i][j] != -1) res = max(res, dist[i][j]);
			}
		}
		return res;
	}
};

int main() {
	return 0;
}
