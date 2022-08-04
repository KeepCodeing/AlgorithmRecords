#include <iostream>
using namespace std;
/*通过查看相关解析，发现了这个解法，用到了数论的知识，3的幂次的质因子只有3，而
所给出的n如果也是3的幂次，故而题目中所给整数范围内最大的3的幂次的因子只能是3的幂
次，1162261467是3的19次幂，是整数范围内最大的3的幂次*/
// 按照评论的思路，这种算法可以推广到n的幂次，只要求出n的最大幂次即可 
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
    }
};
int main() {
	return 0;
}
