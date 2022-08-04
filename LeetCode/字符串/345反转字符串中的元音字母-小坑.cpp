#include <iostream>
#include <algorithm>
using namespace std;
// ˼·��˳�����������Ԫ����ĸ��¼���±꣬�´�����Ԫ����ĸ�����±꽻������
// �����±� 

// ��ʵ֤��˳�򽻻�׹���ˣ����ǵ���˫ָ���˼����Ž��� 
class SolutionFail {
public:
    string reverseVowels(string s) {
    	int sLen = s.size();
    	int index = -1;
    	char tChar;
        for (int i = 0; i <= sLen; i++) {
        	char temp = tolower(s[i]);
        	if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
        		// ��������д��������ȫ���������Ԫ����ĸ�����ڵ�0λʱelse�Ͳ���ִ�� 
        		// ��д��-1 
        		if (index == -1) {
        			index = i;
				} else {
					// ���ﱾ����i++��ֹ�ظ������ģ�Ȼ�������˳�򽻻��Ļ�����д�����Ǵ�� 
        			tChar = s[index];
        			s[index] = s[i];
        			s[i] = tChar;
					index = i;
				}
			}
		}
		return s;
    }
};
class Solution {
public:
	bool isCase(char c) {
		// ע������֮ǰд�� tolower(c) == 'a' || c == ...������дֻ��A�������Сд�� 
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) { 
        	// �������Ԫ���ַ������ƽ� 
        	if (!isCase(s[left])) left++;
			else if (!isCase(s[right])) right--;
			// �������Ԫ���ַ��ˣ��������ٸ���λ�ã���ֹ�ظ����� 
			else swap(s[left++], s[right--]);
		}
		// cout << s;
		return s;
    }
};
int main() {
	Solution s = Solution(); 
	s.reverseVowels("Ui");
	return 0;
}
