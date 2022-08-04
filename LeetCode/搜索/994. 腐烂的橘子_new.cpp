// ��STL����...��ǰWA�巢���Ǹ���̬��... 
#define x first
#define y second
typedef pair<int, int > PII;
class Solution {
public:
    queue<PII > que;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dist[n + 10][m + 10];
        int mv[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        memset(dist, -1, sizeof dist);
        // �����ж��Ƿ��������Ӷ�����Ⱦ��
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // ֻҪ���ǿյ�Ԫ���һ��������
                if (grid[i][j]) cnt++;
                if (grid[i][j] == 2) que.push(PII(i, j)), dist[i][j] = 0;
            }
        }
        while (que.size()) {
            PII now = que.front();que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
                if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
                if (!grid[nx][ny] || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[now.x][now.y] + 1;
                que.push(PII(nx, ny));
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            	// �ų�û�б���Ⱦ���ĵط����������������û����ȾҲ�ᱻ�ų����������ж��Ƿ��������Ӷ�����Ⱦ������ 
                if (dist[i][j] != -1) {
                    res = max(res, dist[i][j]);
                    cnt--;
                }
            }
        }
        if (cnt) res = -1;
        return res;
    }
};
