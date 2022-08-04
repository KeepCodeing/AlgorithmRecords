#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	string result;
	// �ж��Ƿ���Ԫ���ַ� 
	bool isYAlpha(char c) {
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	} 
	vector<string > splitStr(string S) {
		S += ' ';
		int sLen = S.size();
		string temp, tempIndex;
		string resultTemp;
		vector<string > result;
		// �����ַ������ַ����д��� 
		for (int i = 0; i <= sLen; i++) {
			if (S[i] != ' ') {
				temp += S[i];
			} else {
				// �����������ַ�����ӵ�a��Ҫ���� 
				tempIndex += "a";
				// Ԫ���ַ� 
				if (isYAlpha(temp[0])) {
					resultTemp += temp + "ma";
				} else {
					// ��Ԫ���ַ� 
					resultTemp += temp.substr(1, temp.size() - 1);
					// �ӣ�ֱ�Ӽ�temp[0]�����д���temp[0]�����ַ���������ֱ������ 
					resultTemp += temp.substr(0, 1) + "ma";
				}
				// ���a��׺ 
				resultTemp += tempIndex;
				result.push_back(resultTemp);
				
				resultTemp.clear(); 
				temp.clear();
			}
		}
		return result;
	}
    string toGoatLatin(string S) {
        if (S.size() <= 0) return S;
        string result;
        vector<string > t = splitStr(S); 
        for (int i = 0; i < t.size(); i++) {
        	result += t[i];
        	if (i != t.size() - 1) result += ' ';
		}
		return result;
    }
};
int main() {
	Solution s = Solution();
	cout << s.toGoatLatin("I speak Goat Latin"); 
	return 0;
}
