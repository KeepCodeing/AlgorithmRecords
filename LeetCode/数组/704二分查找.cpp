#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// �Լ�ʵ�ֶ��ֲ��ұȽ��鷳�����ÿ⺯������ 

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if (nums.size() == 0 || nums.empty()) -1;
    	// ��һ��[a,b)�����ڲ���target�����ҵ��˷���true�����򷵻�false 
    	// binary_search(nums.begin(), nums.end(), target); 
    	// lower_bound ����ͼ���������[first, last)��Ѱ��Ԫ��value��
    	 
	    // ���[first, last)���еȼ���value��Ԫ��,lower_bound����һ��iteratorָ�����е�һ��Ԫ�ء�
	    // ���û��������Ԫ�ش��ڣ����㷵�ؼ���������Ԫ�ش��ڵĻ�,����ֵ�λ�á���ָ���һ����С
		// ��value��Ԫ�ء����value����[first, last)���κ�һ��Ԫ�أ��򷵻�last��
    	vector<int>::iterator fr = lower_bound(nums.begin(), nums.end(), target);
    	int result = -1;
    	// ����ҵ���
    	// it != nums.end()&& *it == target���۵�д������֪��Ϊʲô��ֱ�ӱ����� 
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
