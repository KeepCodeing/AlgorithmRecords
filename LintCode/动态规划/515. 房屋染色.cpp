#include <iostream>
#include <vector>
using namespace std;

// 这是个二维的序列DP
// 首先考虑能不能按照坐标dp的套路来搞。
// 首先找到最后一步是什么：因为一共有红黄蓝三种颜色，所以最后一个房子被涂上的颜色一定是红色，或黄色或蓝色
// 那么假设一共有N个房子，则第N个房子涂什么颜色花费最小就是问题的解，即f[N] = min(红色+红色的花费, 黄色+黄色的花费,..)
// 但是我们再考虑下，题目还要求相邻的两个房子颜色不能相同，上面这个状态转移方程明显只能计算不考虑颜色相邻的情况
// 也就是说单纯的套模板或者只考虑花费的情况是不行的

// 接下来考虑加一维状态
// 既然选第N个房子还要考虑第N-1个房子的颜色，那么我们大可再加一维状态，设f[i][颜色]表示第i个房子选择了某个颜色的最小花费
// 于是问题就可以转换为第N个房子选了什么颜色的花费最小并且第N-1个房子的颜色和第N个房子不同...
// 那么min{f[N][所有颜色]}就是问题的解了。为了保证第N个房子的花费最小，也就需要保证第N-1个房子的花费最小，所以我们可以
// 枚举第N-1个房子选红色，黄色，还是蓝色的花费最小，然后考虑当第N个房子选的颜色和第N-1个房子选的颜色不同时，第N个房子最少
// 花多少钱

// 然后考虑下初始值，第一个房子的花费一定就是各个颜色的花费，而对于当前房子来说，先默认它没有涂颜色，也就是把花费设置为INF 

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int> > &costs) {
        // write your code here
        if(!costs.size()) return 0;
        int f[10000][3];
        int cLen = costs.size();
        // 第一个房子的花费就是各个颜色的花费 
        f[0][0] = costs[0][0], f[0][1] = costs[0][1], f[0][2] = costs[0][2];
        for (int i = 1; i < cLen; i++) {
        	// 依次枚举前一个房子选颜色k，当前房子选颜色j的情况 
        	for (int j = 0; j < 3; j++) {
        		f[i][j] = 0x3fffffff;
				for (int k = 0; k < 3; k++) {
        			if (j == k) continue;
        			// 对比当前房子的花费是否最小，也就是判断下前一个元素选颜色k加上当前元素选颜色j的花费 
        			f[i][j] = min(f[i][j], f[i - 1][k] + costs[i][j]);
				}
			}
		}
		return min(f[cLen - 1][0], min(f[cLen - 1][1], f[cLen - 1][2]));
    }
}; 

int main() {
	return 0;
}
