// 神坑打卡题，当然也可能是自己没读懂题意...不过最长公共子序列的板子有点忘了... 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        // 注意这里两个特判，题目说的是s是t的子序列，也就是说当s是空串时，必是子序列，而当t是空串时，必然不是... 
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
