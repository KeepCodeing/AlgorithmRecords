#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ��������Ҫ�Ǹ�ȥ�ص����⣬�����������ټ�¼��һ��Ԫ��

// ���ݽ� 
// ������̣���д�˰���û��������ʱ����һ���Ӽ�����Ľ⣬ͼҲ����ȴ��֪������ôȡ
// �ڵ�...��������ϰ���ɱ� 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > nums;
	void dfs(int level, int deepth) {
		result.push_back(temp); 
		// ��¼�Ƿ����һ��Ԫ����ͬ 
		int pre = nums[0] - 1;
		for (int i = level; i < deepth; i++) {
			// ��ͬ˵�������ظ��⣬���м�֦ 
			if (pre == nums[i]) continue;
			temp.push_back(nums[i]);
			dfs(i + 1, deepth);
			// ���½ڵ�ֵ 
			pre = nums[i];
			temp.pop_back(); 
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        sort(nums.begin(), nums.end());
        this->nums = nums;
		dfs(0, this->nums.size());
		return result;
    }
};

// DFS��׹��... 
// DFS�ⷨ�ƺ���������ȥ�أ�����Ԫ�� 
//class Solution {
//public:
//	vector<vector<int> > result;
//	vector<int > temp;
//	vector<int > nums;
//	int pre;
//	void dfs(int level, int deepth) {
//		if (level == deepth) {
//			result.push_back(temp); 
//			return;
//		}
//		if (pre == nums[level]) {
//			return;
//		}
//		// cout << pre << ' ' << nums[level] << endl;
//		temp.push_back(nums[level]);
//		dfs(level + 1, deepth);
//		pre = nums[level];
//		temp.pop_back();
//		dfs(level + 1, deepth); 
//		
//	}
//    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
//        if (nums.size() == 0 || nums.empty()) return result;
//        sort(nums.begin(), nums.end());
//        pre = nums[0] - 1;
//        this->nums = nums;
//		dfs(0, this->nums.size());
//		
//		//result.push_back() 
//		return result;
//    }
//}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	vector<vector<int > > r;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3); 
	// v.push_back(2); 
	r = s.subsetsWithDup(v); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
