#include <iostream>
#include <vector>
#include <map>
// ����֮�ͣ��ù�ϣ����������
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int > m;
        int nLen = nums.size();
        for (int i = 0; i < nLen; i++) {
        	// ����ҵ�����һ�����������±� 
        	if (m.count(target - nums[i])) {
        		vector<int > result(2);
        		result[0] = m[target - nums[i]];
        		result[1] = i;
        		return result;
			}
			// �����¼��ǰ�������±� 
			m[nums[i]] = i; 
		}
		// ע����һ�䣬�����һ�������ձ����и�����ֵ����Ȼ�޷����� 
		return result;
    }
};
int main() {
	Solution s = Solution();
	 
	return 0;
}
