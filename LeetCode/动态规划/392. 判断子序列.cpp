// ��Ӵ��⣬��ȻҲ�������Լ�û��������...��������������еİ����е�����... 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        // ע�������������У���Ŀ˵����s��t�������У�Ҳ����˵��s�ǿմ�ʱ�����������У�����t�ǿմ�ʱ����Ȼ����... 
        if (m == 0) return true;
        if (n == 0) return false;
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[m][n] == m || f[m][n] == n;
    }
};
