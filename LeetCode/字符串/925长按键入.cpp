#include <iostream>
using namespace std;
// ����������ͳ���ַ�������Ȼ��Ա�
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
    	if (name.size() == 0 || typed.size() == 0) return false;
        int cnt[26];
        int tLen = typed.size(), nLen = name.size();
        for (int i = 0; i < tLen; i++) {
        	cnt[typed[i] - 'a']++;
		}
		for (int i = 0; i < nLen; i++) {
			cnt[name[i] - 'a']--;
			if (cnt[name[i] - 'a'] < 0) return false;
		}
		return true;
    }
}; 
int main() {
	Solution s = Solution();
	cout << s.isLongPressedName("saeed", "ssaaedd"); 
	return 0;
}
