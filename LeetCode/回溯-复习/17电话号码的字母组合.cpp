#include <iostream>
#include <vector>
#include <map>
using namespace std;
// û��Ū���ĵ㣺level��i���һ��ʼд����i=level������д�޷����������ַ������ְ�
// levelд����i�������Ļ�û�취����������һ���Ч��

// ���������i��0��ʼ���ɱ����ַ������ȣ���������ڵ��ַ�����Ҫƴ�ӵģ�level��������
// �����������������Ч�� 

// �������ջ��ڻ��ݹ�����ʱ����԰Ѷ�Ӧ��ѭ�������д����������֧��Ӧ��ѭ��������
// �Ĳ�ζ�Ӧ��level��ͬʱ���԰�ÿһ������Щ������Ҫѭ������Щ�������Բ�����֧д���� 

class Solution {
public:
	vector<string > result;
	void dfs(int deepth, string str, string digits, map<char, string > m, int level) {
		if (str.size() == deepth) {
			// cout << str << endl; 
			result.push_back(str);
			return; 
		}
		string mStr = m[digits[level]];
		for (int i = 0; i < mStr.size(); i++) {
			// ����...֮ǰ����i��Ϊ��������ȥ�ˣ��������û���ã������
			// ����Ҳ����ģ�壬ֻ����i�Ӷ�ֵ��ʼ��... 
			dfs(deepth, str + mStr[i], digits, m, level + 1);
		}
	}
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || digits.size() == 0) return result;
        map<char, string > m;
        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl", m['6'] = "mno";
    	m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
    	dfs(digits.size(), "", digits, m, 0);
    	return result;
	}
};
int main() {
	Solution s = Solution();
	s.letterCombinations("23"); 
	return 0;
}
