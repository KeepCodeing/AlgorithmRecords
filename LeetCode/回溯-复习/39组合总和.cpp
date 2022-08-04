#include <iostream>
#include <vector>
using namespace std;
// �о��������ظ�ʹ�õ������е����Ƶ绰����������⣬����Ҫ�ڲ�ε�����������в��� 

// ԭ���绰��������Ǹ����levelд��i����Ϊ��һ���ԭ����һ��û����һ��Ķ����ѡ�񷽰���
// ���Բ���Ҫ����ָ����һ�������Щѡ�� 

class Solution {
public:
	vector<vector<int> > result;
	// ��˵vector�Ӹ�&���÷����Լӿ������ٶȣ� 
	void dfs(int level, int deepth, int target, int sum, vector<int >& temp, vector<int>& candidates) {
		// �ⲻ�Ϸ�����Ȼ��Ҳ����д��ѭ���� 
		if (sum > target) return;
		if (sum == target) {
			result.push_back(temp); 
			return;
		}
		for (int i = level; i < deepth; i++) {
			sum += candidates[i];
			temp.push_back(candidates[i]); 
			// ����˼·���������sum������⣬���ݵ���һ��ʱi�ͻ���������������ٴν��еݹ�ʱ
			// �ͻ�����һ���� 
			dfs(i, deepth, target, sum, temp, candidates);
			sum -= candidates[i];
			temp.pop_back();
		}
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0 || candidates.empty()) return result;
        vector<int > temp;
        dfs(0, candidates.size(), target, 0, temp, candidates);
        return result;
    }
};
int main() {
	vector<int > c;
	vector<vector<int > > result;
	c.push_back(2);
	c.push_back(3);
	c.push_back(6);
	c.push_back(7);
	Solution s = Solution();
	result = s.combinationSum(c, 7);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
