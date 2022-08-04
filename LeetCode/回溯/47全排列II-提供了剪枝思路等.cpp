#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 分析：这个题主要还是剪枝的问题，参考了评论解答，对于有重复元素的树的剪枝大概可以分为
// 两步：1.对有重复元素的数组进行排序，2.利用一个变量记录上次递归的节点值，在当前递归判断
// 当前元素是否等于上次递归的元素（因为已经排序了，所以一定可以用这种方法去重），如果等于
// 说明即将产生的分支是重复的，即可以跳过当前递归 

// 关于这个题似乎也可以直接用set去重，然而效率极低，不考虑 

// 这个题的全排列写法也和其一直以来的写法不同，之前的写法没用vector，所以没办法去除尾部元素
// 这导致添加某个排列时result的下标用的是level，而用vector下标写i就行。 
 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > nums;
	int *visited;
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		// 一开始这个 pre 值必须是整个数组中没有出现的，因此下边界 - 1 或者是上边界 + 1，均可
        // 如果数组中有 int 类型的最大值或者最小值，可能会存在问题，好在这题里没有极端数据
		int pre = nums[0] - 1;
		for (int i = 0; i < deepth; i++) {
			// 两个剪枝条件，使用过或者与上一个节点重复 
			if (visited[i] || nums[i] == pre) continue;
			visited[i] = 1;
			// 添加解 
			temp.push_back(nums[i]);
			dfs(level + 1, deepth);
			visited[i] = 0;
			// 更新pre的值
			pre = nums[i]; 
			temp.pop_back(); 
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return result;
        // 排序，方便剪枝 
        sort(nums.begin(), nums.end());
        int nLen = nums.size();
        this->nums = nums;
        visited = new int[nLen]();
        dfs(0, nLen);
        return result;
    }
};
int main() {
	Solution s = Solution();
	vector<int > t;
	t.push_back(1);
	t.push_back(1);
	t.push_back(2);
	vector<vector<int > > re;
	re = s.permuteUnique(t); 
	for (int i = 0; i < re.size(); i++) {
		for (int j = 0; j < re[i].size(); j++) {
			cout << re[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
