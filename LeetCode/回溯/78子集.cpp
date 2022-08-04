#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// ���������ݹ�������ȷÿһ������ЩԪ�أ�һ��ѡһ��Ԫ��
// ������������˳��������ӵ�ѡ�����黹�Ǻ���ӵ�ѡ��������� 

// DFSǰ�к������д�����ı���ӽ�λ�ü��ı�������� 
// ������ƺ������˳��û��Ҫ�� 
class Solution {
public:
	vector<vector<int> >result;
	vector<int > temp;
	void dfs(int level, int deepth, vector<int>& nums) {
		if (level == deepth) {
			result.push_back(temp);
		} else {
			// ��ӽ�д������˵����ȫ��ѡ���������������������ȫѡ���������� 
			dfs(level + 1, deepth, nums);
			// ��ʼ��ӽ� 
			temp.push_back(nums[level]);
			dfs(level + 1, deepth, nums);
			// �ص���һ���ڵ� 
			temp.pop_back();
		}
	}
    vector<vector<int> > subsets(vector<int>& nums) {
    	if (nums.size() <= 0) return result;
    	sort(nums.begin(), nums.end());
        dfs(0, nums.size(), nums);
        
        for (int i = 0; i < result.size(); i++) {
        	for (int n = 0; n < result[i].size(); n++) {
        		cout << result[i][n] << ' ';
			}
			cout << endl;
		}
		return result;
    }
}; 
// �����㷨�� 
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res,tmp,nums,0);
        for (int i = 0; i < res.size(); i++) {
        	for (int n = 0; n < res[i].size(); n++) {
        		cout << res[i][n] << ' ';
			}
			cout << endl;
		}
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
    	// ��ӽ������ 
        if(tmp.size()<=nums.size()){
            res.push_back(tmp);
        }
        for(int i=level;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};

int main() {
	Solution2 s = Solution2();
	vector<int > temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);   
	s.subsets(temp); 
	return 0;
}
