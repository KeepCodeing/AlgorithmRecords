#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 给出一个数组，找出两个值相加等于目标值
// 纯暴力解法时间复杂度为O(n^2)，原因是可能存在重复对比，而使用map存储
// 结果可以省去很多不必要的对比，这里的思路和DP类似

// 时间复杂度O(n)
vector<int > twoSum(vector<int > &nums, int target) {
	map<int, int > num2index;
	vector<int > result(2);
	for (int i = 0; i < nums.size(); i++) {
		// 在key里查找是否有另一个数 
		if (num2index.count(target - nums[i])) {
			// 取出下标 
			result[0] = num2index[target - nums[i]];
			result[1] = i;
			return result;
		} 
		num2index[nums[i]] = i;
	}
}
 

int main() {
	vector<int > nums;
	int target;
	for (int i = 0; i < 10; i++) nums.push_back(i*i);
	cin >> target;
	vector<int > r = twoSum(nums, target);
	
	cout << nums[r[0]] << ' ' << nums[r[1]] << endl;
	return 0;
}
