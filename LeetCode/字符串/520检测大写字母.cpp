#include <iostream>
using namespace std;
// ˼·��һ��������״̬��ȫΪ��д��ĸ����ͷΪ��д��ĸ���ΪСд��ĸ��ȫΪСд��ĸ
// ȫΪ��д��ĸ��ȫΪСд��ĸҪ���д/Сд��ĸ�ĳ��ִ������ַ�������ȣ���ͷΪ��д
// ��ĸ���ΪСд��ĸҪ���д��ĸֻ����һ�Σ�����Сд��ĸ���ִ�����ӵ����ַ�����
// �Ȳ����ַ�����ͷΪ��д 
class Solution {
public:
    bool detectCapitalUse(string word) {
    	int wLen = word.size();
    	int bCnt = 0, lCnt = 0;
    	// ͳ��ĳ�����ʵĴ�Сд��ĸ���� 
        for (int i = 0; i < wLen; i++) {
        	if (word[i] <= 'Z' && word[i] >= 'A') bCnt++;
        	else if (word[i] <= 'z' && word[i] >= 'a') lCnt++;
		}
		// ���ȫΪ��д��ĸ
		if (bCnt == wLen) return true;
		// ���ȫΪСд��ĸ
		if (lCnt == wLen) return true;
		// �����ͷΪ��д��ĸ����ΪСд��ĸ
		if ((bCnt == 1 && lCnt != 0) && (bCnt + lCnt == wLen) && (word[0] <= 'Z' && word[0] >= 'A')) return true;
		// ����Ϊ���Ϸ��ַ�
		return false; 
    }
}; 
int main() {
	Solution s = Solution();
	string str;
	cin >> str;
	cout << s.detectCapitalUse(str);
	return 0;
}
