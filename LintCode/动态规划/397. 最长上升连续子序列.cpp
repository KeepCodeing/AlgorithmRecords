#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 这种题似乎做了ao多遍了，不过好像还是没什么印象..
// 考虑下最后一步，最后一个被选择的元素一定是j这个位置的元素，那么划分出的子问题就是当我们选第j个元素时，
// j-1位置的元素一定是小于/大于第j个位置的元素。
// 接下来考虑状态转移方程，我们设f(j)=选第j个元素的最长子序列，那么f(j) = max{f(j-1)+1}，并且f[j-1]是小于/
// 大于f[j]的
// 初始值和边界的选择，我们令f[0] = 0，即一个元素都不选那这个序列的长度就为0，边界不存在 

// 上面的思路存在一些问题
// 首先是大于/小于这块，其一开始想的是跑两遍，然而正解是直接旋转整个数组，这样不管是单调上升还是单调下降，都可以用
// f[i - 1] < f[i]来判断。另外大于/小于是指类似5 4 3 2 1这样的数据，如果是求上升序列的话这里就不能直接套模板了。
// 另外就是动态转移方程了，其还是想套模板所以写了个max{f(i - 1) + 1, f(i)}，但是考虑问题的意思，f[i]的长度就是f[i - 1] + 1
// 还有就是初始值的设定，其设了个f[0] = 0，意思是不选元素序列长为0，但是这样似乎并没有什么用。考虑每个元素自己的最长
// 上升连续序列就是其自身，所以正确的初始值设置应该是f[i] = 1... 

// 还有问题w，其实本five认为的跑两遍没问题，只不过教程没看清楚... 

class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int cal(vector<int >& A) {
    	int res = -1, aLen = A.size();
    	int f[aLen + 10];
    	for (int i = 0; i < aLen; i++) {
    		// 每个元素的初始长度就是他自己 
			f[i] = 1;
			// 状态转移方程 
			if (i > 0 && A[i] >= A[i - 1]) f[i] = f[i - 1] + 1;
		}
	    for (int i = 0; i < aLen; i++) res = max(res, f[i]);
		return res;
	}
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int aLen = A.size();
        if (!aLen) return 0;
        // 正着算一遍，反着算一遍，这样就可以把正序，逆序的最长连续子序列都算到 
		int t1 = cal(A), res = -1;
		reverseVec(A);
		res = max(t1, cal(A));
		return res;
    }
    void reverseVec(vector<int >& A) {
    	int l = 0, r = A.size() - 1;
    	while (l < r) swap(A[l++], A[r--]);
	}
};
/*
f[0] = 0;
int vLen = vec.size();
for (int i = 1; i < vLen; i++) {
for (int j = 1; j < i; j++ {
	f[j] = max(f[j], f[j - 1] + 1)
}
	if (vec[i - 1] < vec[i]) f[i] = max(f[i], f[i - 1] + 1);
}
*/
int main() {
	return 0;
}
