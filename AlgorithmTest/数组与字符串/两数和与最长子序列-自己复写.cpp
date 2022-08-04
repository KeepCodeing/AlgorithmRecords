#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 两数和
vector<int > twoSum(vector<int > nums, int target) {
	map<int, int > numAndIndex;
	vector<int > resultIndex(2);
	for (int i = 0; i < nums.size(); i++) {
		if (numAndIndex.count(target - nums[i])) {
			resultIndex[0] = numAndIndex[target - nums[i]];
			resultIndex[1] = i;
			return resultIndex;
		}	
		numAndIndex[nums[i]] = i;
	}
	
}
void ts() {
	vector<int > arr;
	for (int i = 0; i < 10; i++) arr.push_back(i*i);
	int target;
	cin >> target;
	vector<int > result = twoSum(arr, target);
	cout << arr[result[0]] << '+' << arr[result[1]] << '=' << target << endl;
}
struct Bound2 {
	int high;
	int low;
	// 注意这里一定要给结构体的变量一个初始值
	// 不然map在获取不存在的key的value时不知道怎么给结构体初始值 
	Bound2(int h = 0, int l = 0) {
		high = h, low = l;
	}
};
// 最长上升子序列
int longest(vector<int > nums) {
	map<int, Bound2> numMap;
	int maxLen = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (numMap.count(nums[i])) continue;
		int current = nums[i], low, high;
		low = high = current;
		if (numMap.count(current - 1)) {
			low = numMap[current - 1].low;
		}
		if (numMap.count(current + 1)) {
			high = numMap[current + 1].high;
		}
		if (high - low >= maxLen) {
			maxLen = high - low;
		}
		// 这里的规律是如果当前数是最大数，那么最大数就是当前数，相反
		// 最低数同理，与此同时更新最高值和最低值，在这里，最低数的最低值
		// 永远是它自己，最高数的最高值也永远是它自己，所以每次更新时只需要
		// 更新最低数的最高值和最高数的最低值 
		numMap[current].high = numMap[low].high = high;
		numMap[current].low = numMap[high].low = low;
	}
	return maxLen;
} 
void l() {
	vector<int > arr;
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(6);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(11);
	cout << longest(arr) << endl;
}
int main() {
	l();
	return 0;
}
