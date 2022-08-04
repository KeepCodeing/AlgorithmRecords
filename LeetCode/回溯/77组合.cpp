#include <iostream>
#include <vector>
using namespace std;
// ����������ȫ���У�Ӧ��Ҳ�Ǹ���ģ�����
class Solution {
public:
	vector<int > temp;
	vector<vector<int> > result;
	void dfs(int level, int deepth, int n) {
		// ���ڳ����������ƺ�û��Ū���������� 
		// ֮ǰд����2����ʵ����... 
		if (temp.size() == deepth) {
			for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
			result.push_back(temp); 
			return;
		}
		for (int i = level; i <= n; i++) {
			temp.push_back(i);
			dfs(i + 1, deepth, n);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > combine(int n, int k) {
        if (k == 0) return result;
        dfs(1, k, n);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	s.combine(4, 2); 
	return 0;
}
