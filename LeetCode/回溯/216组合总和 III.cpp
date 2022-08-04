#include <iostream>
#include <vector>
using namespace std;
// ���������û��ݣ���1��ʼ�����о٣���������Ϊ��������ĳ����������˺�

// dfs�⣬����ⷢ�ֻ��ݽ�Ļ���Ҫ�ж�ʣ�¶��ٸ�����ѡ����Ӧ�ĳ�������ҲҪ��д�� 
class Solution {
public:
	int target;
	vector<int > temp;
	vector<vector<int > > result;
	// level����ǰ����deepth��������vector��С��sum��ŵ�ǰ��
	void dfs(int level, int deepth, int sum) {
		// ��������
		if (level >= 10 || sum >= target) {
			if (sum == target && temp.size() == deepth) result.push_back(temp); 
			return;
		} 
		// ��ʼ��̽
		temp.push_back(level);
		sum += level;
		dfs(level + 1, deepth, sum);
		sum -= level;
		temp.pop_back(); 
		dfs(level + 1, deepth, sum);
	}
    vector<vector<int> > combinationSum3(int k, int n) {
    	if (k == 0 || n == 0) return result;
    	this->target = n;
        dfs(1, k, 0);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<vector<int > > v;
	v = s.combinationSum3(3, 7);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
