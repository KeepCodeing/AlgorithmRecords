#include <iostream>
#include <algorithm>
using namespace std;
// ��Ϊ�����Ǵ�Сд�����ŵȣ����Կ���ȥ���������ַ���Ȼ����һ�����ַ����ٷ�ת�Ա�
// ע����Ŀ��˵���ַ�Ҳ������ַ��������п������Ȼ����û�У�

// �ֺ��Ե������ֵ���������� 
class Solution {
public:
	char toLowCase(char c) {
		return c >= 'A' && c <= 'Z' ? c + 32 : c;
	}
    bool isPalindrome(string s) {
    	int sLen = s.size();
    	string temp1, temp2;
    	for (int i = 0; i < sLen; i++) {
    		// ���������� 
    		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
    			temp1 += toLowCase(s[i]);
			}
			
		}
		temp2 = temp1;
		reverse(temp1.begin(), temp1.end());
		// cout << temp2 << endl << temp1 << endl;
		return temp1 == temp2;
    }
};
int main() {
	Solution s = Solution();
	cout << s.isPalindrome("0P");
	return 0;
}
