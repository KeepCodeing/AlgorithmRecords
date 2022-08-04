#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ���������ַ����Կո�Ϊ���޲�ֳɶ�����ַ������ɣ����ڷ�ת�����ÿ⺯����Ҳ������˫ָ��
// ���̣���û�ÿ⺯��Ч�ʵ͵Ĳ���... 

// ���ַ�ת���ƺ������Ƚ��ַ����з�Ϊ�മ�����һ�����ԼӸ��ո�ָ��� ��Ȼ������ջ���� 
class Solution {
public:
	vector<string > splitStr(string s, char reg) {
		vector<string > result;
		// ���������s����Ӹ�reg�����Է�ֹ©�����һ���ַ��� 
		s += reg;
		int sLen = s.size();
		string temp;
		for (int i = 0; i < sLen; i++) {
			if (s[i] != reg) {
				temp += s[i];
			} else {
				result.push_back(temp);
				temp.clear(); 
			}
		}
		return result;
	}
	string reverseStr(string s) {
		vector<string > strs = splitStr(s, ' ');
		string result;
		int sLen = strs.size();
		for (int i = 0; i < sLen; i++) {
			int left = 0, right = strs[i].size() - 1;
			while(left < right) {
				swap(strs[i][left++], strs[i][right--]);
			}
			result += strs[i];
			if (i != sLen - 1) result += ' ';
		}
		return result;
	}
    string reverseWords(string s) {
        if (s.size() == 0 || s.empty()) return "";
        return reverseStr(s);
    }
};
int main() {
	Solution s = Solution();
	cout << s.reverseWords("Let's take LeetCode contest"); 
	return 0;
}
