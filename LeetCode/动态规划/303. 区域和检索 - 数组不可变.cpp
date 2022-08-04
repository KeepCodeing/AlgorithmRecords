#include <iostream>
#include <vector>
using namespace std;

// 发现自己大部分入门算的应该都会了，现在开始搞DP，说来奇妙，搞了这么久背包也还是很蒙的样子，图论，搜索之类的题
// 倒是写下模板就会了...不想考虑自己现在会了多少种算法，不过就本five的题量来看260道题应该已经不少了...

// 这题虽然说是dp标签，但是实际上可以用前缀和来做... 

class NumArray {
public:
	vector<int > vec;
    NumArray(vector<int>& nums) {
    	int nLen = nums.size();
    	if (nums.empty()) return;
    	// resize()除了指定大小外还需要指定初始值，至少在LeetCode的评测机上会RE 
        vec.resize(nLen + 10, 0);
		vec[0] = 0;
		for (int i = 1; i <= nLen; i++) {
			vec[i] = vec[i - 1] + nums[i - 1];
		} 
    }
    int sumRange(int i, int j) {
    	// 前缀和下标一直没搞清楚.. 
		return vec[j + 1] - vec[i];
    }
};
int main() {
	return 0;
}
