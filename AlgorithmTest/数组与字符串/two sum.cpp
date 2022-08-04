#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ����һ�����飬�ҳ�����ֵ��ӵ���Ŀ��ֵ
// �������ⷨʱ�临�Ӷ�ΪO(n^2)��ԭ���ǿ��ܴ����ظ��Աȣ���ʹ��map�洢
// �������ʡȥ�ܶ಻��Ҫ�ĶԱȣ������˼·��DP����

// ʱ�临�Ӷ�O(n)
vector<int > twoSum(vector<int > &nums, int target) {
	map<int, int > num2index;
	vector<int > result(2);
	for (int i = 0; i < nums.size(); i++) {
		// ��key������Ƿ�����һ���� 
		if (num2index.count(target - nums[i])) {
			// ȡ���±� 
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
