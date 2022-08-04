// 别样的套板子w，特判过了... 
class Solution {
public:
    int integerBreak(int n) {
    	// 特判，只有2和3的拆分方案是选自己更大，其它数都是能学多个数的 
        if (n == 2) return 1;
        if (n == 3) return 2;
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        // 套板子，n个物品，完全背包从小往大，当前物品价值就是i 
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
            	// 最大容积就是最大乘积... 
                f[j] = max(f[j], f[j - i] * i);
            }
        }
        return f[n];
    }
};
