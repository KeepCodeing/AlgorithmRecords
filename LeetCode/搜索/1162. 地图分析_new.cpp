// STL����Զ���� ����������ģ�����������RE����WA�ģ�����ˢvjudgeר���ʱ��Ҳ��������������ά����ϸ�ڹ��������
// ��ô��������ģ�����ֻ�����ڼ������ˣ��������Թ����·���������֮���... 
typedef pair<int, int > PII;
#define x first
#define y second
class Solution {
public:
    queue<PII > que;
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dist[n + 10][n + 10];
        int mv[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) que.push(PII(i, j)), dist[i][j] = 0;
            }
        }
        // �ж��Ƿ�ȫΪ0��1
        if (!que.size() || que.size() == n * n) return -1;
        while (que.size()) {
            PII now = que.front();que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
                if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[now.x][now.y] + 1;
                que.push(PII(nx, ny));
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dist[i][j]);
            }
        }
        return res;
    }
};
