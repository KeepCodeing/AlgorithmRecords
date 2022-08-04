#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 自己实现二分查找比较麻烦，调用库函数即可 

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if (nums.size() == 0 || nums.empty()) -1;
    	// 在一个[a,b)区间内查找target，查找到了返回true，否则返回false 
    	// binary_search(nums.begin(), nums.end(), target); 
    	// lower_bound 它试图在已排序的[first, last)中寻找元素value。
    	 
	    // 如果[first, last)具有等价于value的元素,lower_bound返回一个iterator指向其中第一个元素。
	    // 如果没有这样的元素存在，它便返回假设这样的元素存在的话,会出现的位置。即指向第一个不小
		// 于value的元素。如果value大于[first, last)的任何一个元素，则返回last。
    	vector<int>::iterator fr = lower_bound(nums.begin(), nums.end(), target);
    	int result = -1;
    	// 如果找到了
    	// it != nums.end()&& *it == target评论的写法，不知道为什么其直接爆错了 
    	if (*fr == target) result = (fr - nums.begin());
		return result;
    }
};

int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(-1); 
	v.push_back(0); 
	v.push_back(3); 
	v.push_back(5); 
	v.push_back(9); 
	v.push_back(12); 
	int t;
	cin >> t; 
	cout << s.search(v, t);
	return 0;
}
