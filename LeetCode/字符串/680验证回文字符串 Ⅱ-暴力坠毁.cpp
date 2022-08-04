#include <iostream>
using namespace std;
// ��������Ŀ˵����ɾ��һ���ַ�����ô���ǿ��Խ���n��ѭ����ÿ��ѭ������n�ַ���������
class Solution {
public:
	bool isHuiWen(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (s[left++] != s[right--]) return false;
		}
		return true;
	}
    bool validPalindrome(string s) {
    	// ���ַ���һ���ַ�������� 
        if (s.size() <=1 || s.empty()) return true;
        // ���ж����ǲ��ǻ��ģ�����Ǿ�û��Ҫɾ���ַ���
		if (isHuiWen(s)) return true;
		// ������ǻ��ģ�����ɾ���ַ�
		int sLen = s.size();
		bool flag = true;
		for (int i = 0; i < sLen; i++) {
			string temp;
			for (int n = 0; n < sLen; n++) {
				if (i == n) continue;
				temp += s[n];
			}
			// ��ǵ�ǰ�����ܷ�ת�� 
			if (!isHuiWen(temp)) flag = false;
			// �������ɻ��ľ�ֱ�ӷ��� 
			else return true;
			temp.clear();
		}
		return flag;
    }
}; 
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.validPalindrome(t); 
	return 0;
}
