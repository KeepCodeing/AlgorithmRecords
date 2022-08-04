#include <iostream>
using namespace std;

// ���������ַ���������乫����Ӵ�����ABCD,DBCT��������Ӵ�����Ϊ2 

// ˼·��������⣬�ӵ�һ����ͬ�ַ������һ����ͬ�ַ�������������Ӵ� 

int longestCommonSubstring(string s1, string s2) {
	if (s1.empty() || s2.empty()) return 0;
	int maxLen = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			int tempIndex = 0;
			// ��ֹ���� 
			while (i + tempIndex < s1.size() && j + tempIndex < s2.size()) {
				// �Ա��ַ�����ͬ��������Ա� 
				if (s1[i + tempIndex] == s2[j + tempIndex]) tempIndex++;
				else break;
			}
			if (tempIndex > maxLen) maxLen = tempIndex;
		}
	}
	return maxLen;
} 

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubstring(s1, s2) << endl;
	return 0;
}
