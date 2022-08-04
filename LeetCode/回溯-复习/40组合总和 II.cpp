#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ��Ҫ�Ǹ�ȥ�ص����⣨�ԣ�

// ����ⲻ���ظ���Ԫ�أ����������һ����˵����ѡһ����һ����ȥ�ش�Ų���Ҫ����Ҫȥ�ص���Ŀ
// Ӧ��������ȫ����II���Ӽ��������⣨��

// ����...������pre��¼��һ��Ԫ����ȥ��

// ΪʲôҪȥ�أ�
// ��Ϊ��������ͬ��ֵ���ӽڵ㣬��ô�����Ļ��ͻ���Ӧ�Ĳ�����ͬ�ķ�֧
// ��һ���Ϸ���ֻ֧����һ�Σ�������Ҫȥ�أ���ô�����Ļ�������ظ�Ԫ��
// ����Ҫ����ȥ�أ���Ϊ�������� 

class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, int target, vector<int >& temp, vector<int >& candidates) {
		if (target < 0) return;
		if (target == 0) {
			result.push_back(temp);
			return; 
		}
		int pre = candidates[0] - 1;
		for (int i = level; i < deepth; i++) {
			// ��֦ 
			if (candidates[i] > target || pre == candidates[i]) continue;
			target -= candidates[i];
			temp.push_back(candidates[i]); 
			dfs(i + 1, deepth, target, temp, candidates);
			target += candidates[i];
			temp.pop_back();
			pre = candidates[i];
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0 || candidates.empty()) return result;
        vector<int > temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates.size(), target, temp, candidates);
        return result;
    }
};
int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(10); 
	v.push_back(1); 
	v.push_back(2); 
	v.push_back(7); 
	v.push_back(6); 
	v.push_back(1); 
	v.push_back(5); 
	vector<vector<int > > r = s.combinationSum2(v, 8); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
