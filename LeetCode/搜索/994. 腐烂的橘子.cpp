#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// ��ԴBFS���·...������Ҫ��������һ�����Ӹ��õ�ʱ�䣬����Ҫ��ӡʲô�ģ����Կ����õ�LeetCode�������һ��С���ɣ�
// ���һ�����õ����ӵĵ���Ծ��Ǹ���ʱ������Ǹ����ӣ�ֱ��ȡ������ܵõ���ʱ�䣬����Ҫ�ٱ������������ 

// �������ƺ��ֲ��У���Ϊ����Ҫ���������Ӷ������ˣ���������ܻ������Ӳ����ã��Ƿ��صľ��Ǵ�� 

// WA����Σ��������������ٸ��ˣ�LeetCode�ϵ�������ͨ���ʼ���... 

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
