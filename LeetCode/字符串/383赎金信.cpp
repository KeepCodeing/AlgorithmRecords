#include <iostream>
#include <map>
using namespace std;
// ˼·��ֻҪԭ�ĵ��ַ��������ŵ��ַ������ɣ�����map����

// �����Ҳ������������ַ���������Ϊ�ַ��޶���Сд�ַ������Կ������±����ַ����� 
// arr[c-'a'].. 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	// ���ԭ�ĵ��ַ���������û���ŵ��ַ����������˵��һ��������� 
        if (magazine.size() < ransomNote.size()) return false;
        int mSize = magazine.size();
        int rSize = ransomNote.size();
        map<char, int > cMap;
		for (int i = 0; i < mSize; i++) {
			cMap[magazine[i]]++;
		}
		for (int i = 0; i < rSize; i++) {
			// ������������û��߸��ַ�����û�г��ֹ��ͷ���false 
			if (cMap[ransomNote[i]] <= 0) return false;
			cMap[ransomNote[i]]--;
		}
		return true;
    }
}; 
int main() {
	Solution s = Solution();
	cout << s.canConstruct("aa", "aab"); 
	return 0;
}
