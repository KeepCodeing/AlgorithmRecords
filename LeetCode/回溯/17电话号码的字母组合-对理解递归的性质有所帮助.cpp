#include <iostream>
#include <vector>
#include <map>
using namespace std;
// �������������Ϊ���Ǻ�������һ����ֻ��һ�����ݵ����壬���Խ�����Ҳ��̫һ��
// ����˵Ҫ��"234"����ϣ�ת������ĸ����m['2'] = "abc", m['3'] = "def", m['4'] = "ghi"��
// ���ǵ����Ϊadg,adh,adi...�� �����ݹ���̾����Ƚ��뵽����Ǹ��ַ����ڵ���һ�㣨��Ͳ㣩
// Ȼ�����һ���ַ����ƴ�ӵ�֮ǰ���ַ�֮���ٻص������ڶ����ַ��ǲ㣬��Ϊ��һ��ĵ�һ��
// �ַ��Ѿ�ƴ�ӹ��ˣ����Խ���ڶ����ַ�ƴ�ӵ�����ٽ������һ������ƴ�ӣ�ֱ�������ַ���������
// ���� 

// �������Ҫ�ǵݹ��˼�룬���ߵ���ǰ�ַ��������Ȼ����ַ���ӳ��ƴ��ȥ��������Ҳ��һ������
// ֮ǰ���������ģ�壬Ҳ�������ĳ����������ܾ��ÿ��ǵ�̫�� 
class Solution {
public:
	vector<string> result;
	string d;
	map<char, string > m;
	void dfs(int level, int deepth, string str) {
		// ������ÿһ���ַ�����ƴ�ӹ��� 
		if (str.size() == deepth) {
			result.push_back(str); 
			return;
		}
		// m[d[level]].size()��d��ԭ�ַ�������"234"��level�ǵ�ǰ��Σ�
		// m��һ��map������ӳ���˼���Ӧ���ַ�������仰����˼���Ǵӵ�һ��
		// �ַ���ʼ����ÿλ�ַ�ȡ����ƴ������� 
		for (int i = 0; i < m[d[level]].size(); i++) {
			// �����ƴ�ַ� 
			dfs(level + 1, deepth, str + m[d[level]][i]);
		}
	}
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0 || digits.empty()) return result;
        this->d = digits;
        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl";
        m['6'] = "mno", m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
        dfs(0, this->d.size(), "");
        return result;
    }
};

// ׹���˵���ģ��� 
//class Solution {
//public:
//	vector<string> result;
//	string t;
//	vector<char > str;
//	void dfs(int level, int deepth, char start) {
//		if (str.size() == deepth && str[0] == start) {
//			string temp;
//			for (int i = 0; i < str.size(); i++) temp += str[i];
//			cout << temp << endl;
//			result.push_back(temp); 
//		}
//		for (int i = level; i < deepth; i++) {
//			str.push_back(t[i]);
//			dfs(i + 1, deepth, start);
//			str.pop_back(); 
//		}
//	}
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0 || digits.empty()) return result;
//        map<char, string > m;
//        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl";
//        m['6'] = "mno", m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
//        for (int i = 0; i < digits.size() - 1; i++) {
//        	string st = m[digits[i]];
//        	for (int j = 0; j < st.size(); j++) {
//        		this->t += st[j];
//        		this->t += m[digits[i + 1]];
//        		dfs(0, t.size(), st[j]);
//			}
//		}
//        return result;
//    }
//};
int main() {
	Solution s = Solution();
	s.letterCombinations("23"); 
	return 0;
}
