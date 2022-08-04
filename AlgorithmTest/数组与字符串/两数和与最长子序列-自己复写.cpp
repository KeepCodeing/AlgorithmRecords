#include <iostream>
#include <vector>
#include <map>
using namespace std;
// ������
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
	// ע������һ��Ҫ���ṹ��ı���һ����ʼֵ
	// ��Ȼmap�ڻ�ȡ�����ڵ�key��valueʱ��֪����ô���ṹ���ʼֵ 
	Bound2(int h = 0, int l = 0) {
		high = h, low = l;
	}
};
// �����������
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
		// ����Ĺ����������ǰ�������������ô��������ǵ�ǰ�����෴
		// �����ͬ�����ͬʱ�������ֵ�����ֵ�����������������ֵ
		// ��Զ�����Լ�������������ֵҲ��Զ�����Լ�������ÿ�θ���ʱֻ��Ҫ
		// ��������������ֵ������������ֵ 
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
