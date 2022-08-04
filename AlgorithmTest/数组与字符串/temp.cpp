#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ht {
	int high;
	int low;
	ht(int h = 0, int l = 0) {
		high = h, l = low;
	}
};
int longest(vector<int > nums) {
	int maxLen = 0;
	map<int, ht > numMap; 
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
		
		if (high - low > maxLen) {
			maxLen = high - low;
		}
		
		numMap[current].high = numMap[low].high = high;
		numMap[current].low = numMap[high].low = low;  
	}
	return maxLen;
}
int main() {
	vector<int > arr;
	for (int i = 0; i < 10; i++) arr.push_back(i);
	cout << longest(arr) << endl; 
	return 0;
}
