// ���⣬����д��Ե�ж�ʱ�е���ɣ���Ҫ��û�и����״̬�����ڱ�Ե�ĵ���ԣ����ǵ�״ֻ̬������һ����ת�ƶ�����
// ����һ��������Щ����أ��޷���һ���߷������������߷���ע�⣺f[i][j]��ʾ����(i, j)���ж������߷������������
// �����˶��ٲ���Ҳ���ǲ�����f[i][j] = f[i - 1][j] + 1֮��ķ�����ת��״̬... 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int f[110][110];
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            	// ע������Ŀӵ��жϣ�����Ҳ�������ϰ������Ե����ж��Ƿ����ϰ�... 
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
