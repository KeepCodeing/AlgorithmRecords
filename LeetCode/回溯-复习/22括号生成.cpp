#include <iostream>
#include <vector>
using namespace std;
// ӡ��Ƚ�����⣬�Ƚ��������������������� �����̣������ǵ��������Ŷ����е�ʱ�������ӣ�
// ���ǵ�����������С������������ʱ��ӣ�����������С������������ֻ�����Ǹ��ݹ����������
// �����Ŵ����������������Խ��м�֦ 

// ����...˼·ûʲô���⣬�����ַ���ӵ�λ�ò��� 
class Solution {
public:
	vector<string > result;
	void dfs(int left, int right, string str) {
		if (left == 0 && right == 0) {
			// cout << str << endl;
			result.push_back(str); 
		}
		if (left > right) return;
		if (left > 0) {
			// ֮ǰ����д�ģ����ɵ�������Ϊ((())) 
			// dfs(left - 1, right, '(' + str);
			dfs(left - 1, right, str + '(');
		} 
		if (right > 0) {
			dfs(left, right - 1, str + ')');
		}
	}
    vector<string> generateParenthesis(int n) {
    	if (n == 0) return result;
    	dfs(n, n, "");
        return result;
    }
};
int main() {
	Solution s = Solution();
	s.generateParenthesis(3); 
	return 0;
}
