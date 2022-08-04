// 完全背包求最小物品数... 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	// 很坑，amount可以为0，这种情况就会返回-1.. 
        if (amount == 0 || coins.empty()) return 0;
        int n = coins.size();
        int f[amount + 1];
        memset(f, 0, sizeof f);
        for (int i = 0 ; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (j == coins[i]) f[j] = 1;
                else if (f[j] == 0 && f[j - coins[i]] != 0) f[j] = f[j - coins[i]] + 1;
                else if (f[j - coins[i]] != 0) f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        return f[amount] == 0 ? -1 : f[amount];
    }
};
