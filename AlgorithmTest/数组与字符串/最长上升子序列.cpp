#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Bound {
	int height;
	int low;
	Bound(int h = 0, int l = 0) {
		height = h, low = l;
	}
};
// 给定一个数组，求出最长连续区间的长度如：5 8 3 2 1 4（这里从3到4都算）

// 思路：每次只需要对比当前元素后一位满不满足当前元素+1或-1即可，因为必定是连续
// 子序列，所以遍历时只用更新其最大最小值即可 

int longest(vector<int > nums) {
	map<int, Bound > table;
	int local, maxLen = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		// 去除重复的情况 
		if (table.count(nums[i])) continue;
		
		local = nums[i];
		int low = local, height = local;
		// 每次遍历时都会利用结构体更新上一个数的最大值和最小值 
		// 如果连续，查找数组中是否存在最小值 
		if (table.count(local - 1)) {
			low = table[local - 1].low;
		}
		// 如果连续，查找数组中是否存在最大值 
		if (table.count(local + 1)) {
			height = table[local + 1].height;
		}
		// 更新最大值和最小值 
		table[low].height = table[local].height = height;
		table[height].low = table[local].low = low;
		
		if (height - low + 1 > maxLen) {
			maxLen = height - low + 1;
		}
	}
	return maxLen;
}
int main() {
	vector<int > v;
	for (int i = 0; i < 10; i++) v.push_back(i);
	cout << longest(v) << endl;
	return 0;
}
