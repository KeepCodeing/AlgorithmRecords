#include <iostream>
using namespace std;

// 这里要补充个同余定理，就是判断(A - B) % K == 0可以写成 A % K == B % K，那么这个题就用到了这个定理
// 一眼可以看出来用前缀和，但是枚举区间又是个O(n^2)的操作，还是回到了暴力上，所以这种方法是不可行的。
// 根据上面的定理，我们设当前前缀和为A，子区间的和为B，如果存在A % K == B % K，就说明这个子区间的和
// 是可以整除K的，但是这里B是未知量，所以得用个HashTable来记录之前所有前缀和的模数。另外要注意将HashTable
// 的0这个键的元素置为0，即特判当前数组的前缀和可以整除K。 

class Solution {
public:
    map<int, int > rec;
    int subarraysDivByK(vector<int>& A, int K) {
        int preSum = 0, res = 0;
        // 初始化当前数组的前缀和可以整除K的情况 
        rec[0] = 1;
        for (auto& i : A) {
        	// 计算前缀和 
            preSum += i;
            // 注意C++取模负数会得到负数，所以这里得加上K修正 
            int mod = (preSum % K + K) % K; // 计算 A % K的余数
			// 如果存在B % K的余数与A % K的余数相等，计算有多少个子区间满足 
            if (rec.count(mod)) {
                res += rec[mod];
            }
            // 存放B % K的余数 
            rec[mod]++;
        }
        return res;
    }
};

int main() {

	return 0;
}
