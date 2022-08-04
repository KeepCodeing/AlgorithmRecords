#include <iostream>
#include <vector>
using namespace std;

// 这是个经典的动态规划题，首先要明确子序列和连续序列的区别，子序列是指从某个位置算起，后面任何一个子串组成的序列
// ，也就是说子序列不要求重复，可以跳着选。连续序列是指从当前位置开始，后面连着的任意子串组成的序列，也就是说连续子序列只能
// 一个一个的选...

// 直接用dp分析方法来做比较难以理解，所以这里先给出状态的定义
// 我们设f[i]为第i个位置的元素的最长上升子序列的长度，那么最后一步就是从这个元素起，我们选第j个位置的元素能获得的新的子序列的
// 长度。由此问题就被划分为是i这个位置的元素的LCS最长还是选j这个位置的LCS最长，那么根据定义，可以得到j这个位置存在LCS的前提是
// j位置的元素的值小于i位置的元素的值，而选j所能带来的最LCS的长度就是当前位置的LCS的长度+1，另外要注意下初始值，我们默认规定
// i这个位置的元素的LCS就是它自身，即f[i] = 1 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int nLen = nums.size();
		vector<int > f(nLen + 10, 0);
		for (int i = 0; i < nLen; i++) {
			f[i] = 1;
			// 枚举这个元素的LCS，然后更新答案 
			for (int j = 0; j < i; j++) {
				// LCS存在的前提就是当前元素更大 
				if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
			}
		}
		int res = 0;
		// 最后每个位置的LCS的最大值就是结果 
		for (int i = 0; i < nLen; i++) res = max(res, nums[i]);
		return res;
    }
};

int main() {
	return 0;
}
