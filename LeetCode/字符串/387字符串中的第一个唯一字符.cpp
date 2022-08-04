#include <iostream>
#include <map>
using namespace std;
// ��������������mapͳ��һ���ַ���������˳������ַ������ĳ���ַ���valueΪ1��˵��
// ���ַ��ǵ�һ��Ψһ�ַ�

// ͬ������������� 
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int > m;
        // ͳ���ַ����� 
        for (int i = 0; i < s.size(); i++) m[s[i]]++;
        for (int i = 0; i < s.size(); i++) {
        	// �ҳ���һ�����ظ����ַ� 
        	if (m[s[i]] == 1) return i;
		}
		// �ַ�ȫ���ظ��˵���� 
		return -1;
    }
}; 
int main() {
	Solution s = Solution();
	string str;
	cin >> str;
	cout << s.firstUniqChar(str);  
	return 0;
}
