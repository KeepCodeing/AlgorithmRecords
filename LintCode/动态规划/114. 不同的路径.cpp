#include <iostream>
using namespace std;

// 思路就是对于(m, n)点，上一步一定是从(m - 1, n)或者(m, n - 1)点走来的，这就是最后一步。
// 那么原问题就可以划分成求机器人走到(m - 1, n)与(m, n - 1)的方案数，这就是子问题。
// 于是我们设f(m, n)=机器人走到(m - 1, n)与(m, n - 1)的方案数，这就是状态的表示。 
// 于是可得f(m, n) = f(m - 1, n) + f(m, n - 1)，这就是状态转移方程。 
// 那么对于(1, 1)点，机器人只有一种不走的方式，机器人不能走到地图外面，这就是边界和初始值。 
// 当机器人走到f(m, n)时，必须保证f(m - 1, n)或者f(m, n - 1)有值，这就是运行顺序。 

// 上面的动态转移方程有问题...其实不止起点是只有一种走法，当我们处于i == 0 || j == 0的地方时，上一步
// 也只可能是由同一种走法走过来的...也就是初始化得在循环里搞... 

class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        int f[110][110];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) f[i][j] = 1;
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main() {
	return 0;
}
