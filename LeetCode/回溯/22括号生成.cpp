#include <iostream>
#include <vector>
using namespace std;
// ������������Ǿ�����������Ż��������ţ�����˵ÿ�λ��ݶ�����һ���Ϸ����ţ�����
// ��Ӧ��������������������Ż���������������ʣ���������������

// ע�������str��������֮ǰһֱ�õ�vector���ַ���������û��Ҫ��... 
class Solution {
public:
	vector<string > result;
	void dfs(string str, int left, int right) {
		// ���������Ŷ������ˣ�˵��������һ���Ϸ��� 
		if (left == 0 && right == 0) {
			result.push_back(str);
			return; 
		}
		// ��֦
		if (left > right) return;
		// ��ֹ������� 
		if (left > 0) dfs(str + "(", left - 1, right);
		if (right > 0) dfs(str + ")", left ,right - 1);
			
	}
    vector<string> generateParenthesis(int n) {
        if (n == 0) return result;
        dfs("", n, n);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<string > t = s.generateParenthesis(3); 
	for (int i = 0; i < t.size(); i++) {
		cout << t[i] << endl;
	}
	return 0;
}
