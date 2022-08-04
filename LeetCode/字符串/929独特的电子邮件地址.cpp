#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 分析：因为匹配规则对域名部分不适用，而@只有一个，所以我们可以先将字符分为本地地址和
// 域名地址两部分，然后对本地地址进行操作。因为字符'.'不对字符构成产生影响，所以我们可以
// 直接把本地地址里的'.'替换掉，然后查找第一个'+'，如果有，则剔除后面全部字符。最后利用
// 一个set去重即可 

// 纯用stl效率太低，可以参考下评论的解法 

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
			// 获取本地地址 
			string left = emails[i].substr(0, index);
			// 获取域名地址 
			string right = emails[i].substr(index);
			// 清除'+'后的元素 
			int leftIndex = left.find('+');
			if (leftIndex != left.npos) {
				left = left.substr(0, leftIndex); 
			} 
			// 替换'.' 
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
