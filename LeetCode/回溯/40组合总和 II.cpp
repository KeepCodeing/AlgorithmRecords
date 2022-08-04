#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ���������ݽ⣬ÿ�εݹ����Ѿ�ʹ�õ������ٴ����ۼƺͣ�������ۼƺʹ���target���ߵ�ǰ��
// ����target�ͷ��أ���ȻҲ������target��ȥ��ǰ�����ж��Ƿ�Ϊ0

//class Solution {
//public:
//	int *visited;
//	vector<int > temp;
//	vector<vector<int > > result;
//	void dfs(int level, int deepth, vector<int>& candidates, int target) {
//		if (target <= 0 || level == deepth) {
//			for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
//			cout << endl;
//			return;
//		}
//		for (int i = level; i < deepth; i++) {
//			if (target - candidates[level] < 0) continue; 
//			if (candidates[i] > target) continue;
////			if (i > level && candidates[i] == candidates[i - 1]) {
////                continue;
////            }
//			temp.push_back(candidates[level]); 
//			dfs(level + 1, deepth, candidates, target - candidates[level]);
//			temp.pop_back();
//		}
//	}
//    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//        visited = new int[candidates.size()]();
//        dfs(0, candidates.size(), candidates, target);
//        delete[] visited;
//        return result;
//    }
//}; 

class Solution {
public:
	vector<int > nums;
	vector<int > temp;
	vector<vector<int > > result;
	int deepth;
	void dfs(int level, int target) {
		// �ҵ���ĳ��ڣ�targetΪ0�������Ѿ��ﵽ�ݹ�������ײ� 
		if (target <= 0 || level == deepth) {
			if (target == 0) {
//				for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
//				cout << endl;
				result.push_back(temp); 
			}
			return;
		}
		for (int i = level; i < deepth; i++) {
			// �жϵ�ǰֵ�Ƿ����target��������ھ�û��Ҫ����target���� 
			if (nums[i] > target) continue;
			// �жϵ�ǰԪ���Ƿ�����һ��Ԫ���ظ�������ظ������Լ�֦ 
			if (i > level && nums[i - 1] == nums[i]) {
                continue;
            }
			temp.push_back(nums[i]); 
			// ע�����ﲻ��level��1��levelֻ�ǵ�ǰ������i���ǵ�ǰѡ��
			// i+1��ʾ��һ��ѡ�� 
			dfs(i + 1, target - nums[i]);
			// dfs(level + 1, target - nums[i]);
			temp.pop_back();
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	// ������������ʹ�����Ԫ�ر�á����ظ������������ظ�Ԫ�ز����ܳ����ڵ�һλ 
    	// ֻ�ж��������������ܼ�֦ 
    	sort(candidates.begin(), candidates.end());
        this->nums = candidates;
        this->deepth = candidates.size();
        dfs(0, target);
//        for (int i = 0; i < result.size(); i++) {
//        	for (int n = 0; n < result[i].size(); n++) {
//        		cout << result[i][n] << ' ';
//			}
//			cout << endl;
//		}
		return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);  
	v.push_back(2);  

	s.combinationSum2(v, 6); 
	return 0;
}
