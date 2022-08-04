// ���ˣ��ñ���ʽ��w
// ��F[i][j]��ʾtext1[1...i - 1]��text2[1...j - 1]��������У��������λ�õ�Ԫ����ȣ������г���+1��
// �������ѡ���߲�ѡ�������ˣ�ѡ��һ������һ���� 
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
