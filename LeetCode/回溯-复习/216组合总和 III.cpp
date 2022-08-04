#include <iostream>
#include <vector>
using namespace std;

// �����һ���������ͣ���һ������ʹ��ͬһ��λ���ϵ����֣��ڶ���������ʹ��ͬһ��λ���ϵ����֣�
// ������������ʹ��ͬһ�����֣���һ����Ҫ���ߵ��ף��ڶ���������ͨ�Ļ����⣬������������ȥ��
// ���ֵ��߼���Ȼ����û��ȥ�أ�ֻ�Ǹ��������ݷ�Χ�� 

class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, int target, vector<int >& temp) {
		if (target < 0) return;
		// ����ĳ���д�ľ���target�������Ԫ�ظ�������� 
		if (target == 0 && temp.size() == deepth) {
			result.push_back(temp);
			return; 
		}
		for (int i = level; i <= 9; i++) {
			if (target < i) continue;
			temp.push_back(i);
			// ��ʵtargetû��Ҫȡ�����Ӽ����ݹ����Զ���ԭ���� 
			dfs(i + 1, deepth, target - i, temp);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > combinationSum3(int k, int n) {
        if (n == 0 || k == 0) return result;
        vector<int > temp;
        dfs(1, k, n, temp);
        return result;
    }
}; 

int main() {
	Solution s = Solution();
	vector<vector<int > > r = s.combinationSum3(3, 9); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
