#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 分析：画递归树，明确每一层有哪些元素，一次选一个元素
// 而左右子树的顺序由先添加到选择数组还是后添加到选择数组决定 

// DFS前中后序遍历写法，改变添加解位置即改变遍历次序 
// 这个题似乎对输出顺序没有要求 
class Solution {
public:
	vector<vector<int> >result;
	vector<int > temp;
	void dfs(int level, int deepth, vector<int>& nums) {
		if (level == deepth) {
			result.push_back(temp);
		} else {
			// 添加解写在其后就说明先全不选，走右子树，否则就是先全选，走左子树 
			dfs(level + 1, deepth, nums);
			// 开始添加解 
			temp.push_back(nums[level]);
			dfs(level + 1, deepth, nums);
			// 回到上一个节点 
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
// 回溯算法解 
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
    	// 添加解的条件 
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
