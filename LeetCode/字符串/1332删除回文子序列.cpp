#include <iostream>
using namespace std;
// ������ɾ�����������У������ǻ������ַ�������Ϊ�����ַ���ֻ��a��b������һ��
// ֻ�����������1.Ϊ�գ�ɾ��0�Σ�2.����Ϊ���ģ�ɾ��1�Σ�3.����Ϊ���ģ�ɾ��2��
class Solution {
public:
	bool isHuiwen(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (s[left++] != s[right--]) return false;
		}
		return true;
	}
    int removePalindromeSub(string s) {
        if (s.empty() || s.size() <= 0) return 0;
        if (isHuiwen(s)) return 1;
        return 2;
    }
}; 
int main() {
	return 0;
}
