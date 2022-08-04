#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ��������Ϊƥ�������������ֲ����ã���@ֻ��һ�����������ǿ����Ƚ��ַ���Ϊ���ص�ַ��
// ������ַ�����֣�Ȼ��Ա��ص�ַ���в�������Ϊ�ַ�'.'�����ַ����ɲ���Ӱ�죬�������ǿ���
// ֱ�Ӱѱ��ص�ַ���'.'�滻����Ȼ����ҵ�һ��'+'������У����޳�����ȫ���ַ����������
// һ��setȥ�ؼ��� 

// ����stlЧ��̫�ͣ����Բο������۵Ľⷨ 

/*int numUniqueEmails(vector<string>& emails) {
	set<string> res; int count = 0; int tmp = 0;
	for (int i = 0; i<emails.size(); ++i)
		for (int j = 0; j<emails[i].size(); ++j) {
			if (emails[i][j] == '@') break;
			if (emails[i][j] == '.') {
				emails[i].erase(j, 1); continue;
			}
			if (emails[i][j] == '+') {
				tmp = j;
				while (emails[i][j] != '@') {
					count++; ++j;
				}
				emails[i].erase(tmp, count);
				count = 0;  break;
			}
		}
	for (auto itm : emails)
		res.insert(itm);
	return res.size();
}
*/
class Solution {
public:
	int checkEmails(vector<string>& emails) {
		int eLen = emails.size();
		set<string > eSet;
		for (int i = 0; i < eLen; i++) {
			int index = emails[i].find('@');
			// ��ȡ���ص�ַ 
			string left = emails[i].substr(0, index);
			// ��ȡ������ַ 
			string right = emails[i].substr(index);
			// ���'+'���Ԫ�� 
			int leftIndex = left.find('+');
			if (leftIndex != left.npos) {
				left = left.substr(0, leftIndex); 
			} 
			// �滻'.' 
			while((leftIndex = left.find('.')) != left.npos) {
				left.replace(leftIndex, 1, ""); 
			}
			left += right;
			eSet.insert(left);
		}
		return eSet.size();
	}
    int numUniqueEmails(vector<string>& emails) {
        if (emails.size() == 0 || emails.empty()) return 0;
        return checkEmails(emails);
    }
};
int main() {
	vector<string > s;
	//"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"
	s.push_back("test.email+alex@leetcode.com");
	s.push_back("test.e.mail+bob.cathy@leetcode.com");
	s.push_back("testemail+david@lee.tcode.com");
	Solution t = Solution();
	cout << t.numUniqueEmails(s); 
	return 0;
}
