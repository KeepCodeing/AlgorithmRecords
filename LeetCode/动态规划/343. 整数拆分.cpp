// �������װ���w�����й���... 
class Solution {
public:
    int integerBreak(int n) {
    	// ���У�ֻ��2��3�Ĳ�ַ�����ѡ�Լ�����������������ѧ������� 
        if (n == 2) return 1;
        if (n == 3) return 2;
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        // �װ��ӣ�n����Ʒ����ȫ������С���󣬵�ǰ��Ʒ��ֵ����i 
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
            	// ����ݻ��������˻�... 
                f[j] = max(f[j], f[j - i] * i);
            }
        }
        return f[n];
    }
};
