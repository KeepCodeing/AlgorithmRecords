#include <iostream>
#include <vector>
using namespace std;

// ѧϰ���ݵĵ�һ���⣬��ʱ�ǿ������dfsд�ģ�������ñ�׼����дһ��...

// ����д�����ˣ��������ֵ��Ի����ٲ��� 
 
class Solution {
public:
	vector<string> result;
	bool isAlpha(char c) {
		return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
	}
	void dfs(int level, int deepth, string str) {
		// ������ȥ����������Ǹ��Ӽ����͵�����... 
		result.push_back(str); 
		for (int i = level; i < deepth; i++) {
			if (isAlpha(str[i])) {
				// ���Զ�ת����Сдд��&��... 
				str[i] ^= (1 << 5);
				dfs(i + 1, deepth, str);
				str[i] ^= (1 << 5);
			}
		}
	}
    vector<string> letterCasePermutation(string S) {
        if (S.size() == 0 || S.empty()) return result;
		dfs(0, S.size(), S);
        return result;
    }
};

int main() {
	Solution s = Solution();
	vector<string > r = s.letterCasePermutation("a1b2");
	for (int i = 0; i < r.size(); i++) cout << r[i] << endl;
	return 0;
}
