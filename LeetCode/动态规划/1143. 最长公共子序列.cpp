// 好了，该背公式了w
// 用F[i][j]表示text1[1...i - 1]和text2[1...j - 1]的最长子序列，如果两个位置的元素相等，则序列长度+1，
// 否则就是选或者不选的问题了（选上一步的哪一个） 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};
