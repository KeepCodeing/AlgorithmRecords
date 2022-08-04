#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ��������ΪԪ�ؿ����ظ�ʹ�ã����Կ��Դ�ͷ����ֱ������˺Ϸ�����ߴ����˺Ϸ���
// �ڽ����´λ��ݣ�����⿴�����Ǹ��Ӽ����͵��⣬·���ϵĽڵ���ܶ�Ҫ�õ� 

// ������ģ����⣬����Ҫע���ʹ����ͬԪ��ʱ���ַǷ�������Զ�������һ��ķ��� 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > c;
	void dfs(int target, int start, int deepth) {
		if (target == 0) {
			result.push_back(temp);
			return; 
		}
		// �ؼ��������ʵ��targetС��0�Զ���������һ��Ĺؼ�������i����start
		// ��������˷Ƿ��⣬�ͻ���뵽��һ����ݣ���ʱi�ͻ�����һ�� 
		for (int i = start; i < deepth; i++) {
			int cur = c[i];
			if (target - cur < 0) continue;
			temp.push_back(cur);
			dfs(target - cur, i, deepth);
			temp.pop_back(); 
		}
	}
	
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return result;
        sort(candidates.begin(), candidates.end());
        this->c = candidates;
        dfs(target, 0, candidates.size());
        return result;
    }
};
int main() {
	return 0;
}
