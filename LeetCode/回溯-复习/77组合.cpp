#include <iostream>
#include <vector>
using namespace std;
// ������ģ�� 

// ����...����ÿһ�ⶼҪ���£�����û�취��...

// ��Ҫ���ǳ�����������һ���ѡ������е���Ҫ�������� 
 
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int k, int n, vector<int >& temp) {
		if (temp.size() == k) {
			result.push_back(temp);
			return; 
		}
		for (int i = level; i <= n; i++) {
			temp.push_back(i);
			dfs(i + 1, k, n, temp);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > combine(int n, int k) {
    	if (n == 0 || k == 0) return result;
    	vector<int > temp;
    	dfs(1, k, n, temp);
        return result;
    }
};
int main() {
	Solution s = Solution();
	vector<vector<int> > t = s.combine(4, 2); 
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t[i].size(); j++) {
			cout << t[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
