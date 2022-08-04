#include <iostream>
using namespace std;

// 小数快速幂，值得一提的是代码基本和整数快速幂差不多，不过这里还是有两个不同的点
// 首先，这里的幂可能是负的，对于这种情况，如果我们只考虑循环次数的话似乎是和整数差不多的，但是实际上这里不能用位移这种方式
// 除半幂，因为负数的补齐位全是1，这样就会形成死循环，所以这里必须用数除，另外虽然循环次数差不多，但是负幂返回的应该是相反数
// 所以最后还得判断下幂的正负
// 其次，这里进行快速幂的是实数，但实际上运算规则和整数是一样的...所以大部分还是套模板... 

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int temp = n;
        while (n) {
        	if (n & 1) res = res * x;
        	// 因为负数的补齐位全是1所以位移会形成死循环，因而这里必须用数乘 
        	n /= 2;
        	x *= x;
		}
		// 如果是负次幂，返回它的相反数就行 
		if (temp > 0) return res;
		return 1 / res;
    }
};

int main() {
	return 0;
}
