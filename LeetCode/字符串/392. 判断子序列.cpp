#include <iostream>
#include <algorithm>
using namespace std;

// ��Ȼ��Ŀ��ǩ�Ƕ�̬�滮�������������string��find�������Ӽ�

// ׹�٣����ǵ�һ�����Ա�
class Solution {
	public:
		bool isSubsequence(string s, string t) {
			if(s.size() == 0)return true;
			int start = 0;
			int len = s.size();
			for(int i = 0; i < t.size(); i++) {
				if(s[start] == t[i])
					start++;
				if(start == len) return true;
			}
			return false;
		}
};
int main() {
	Solution s = Solution();
	s.isSubsequence("abc", "ahbgdc");
	return 0;
}
