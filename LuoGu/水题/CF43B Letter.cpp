#include <iostream>
using namespace std;

// ����һ���ͼ�ۣ�ˢ��ˮ��.. 

// Ͱ����Ŀ˵���ִ�Сд����������������Ͱ 
int upperLetter[26], lowerLetter[26];
int main() {
	string str, words;
	getline(cin, str);
	getline(cin, words);
	// ��Ͱ
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			lowerLetter[str[i] - 'a']++;
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			upperLetter[str[i] - 'A']++;
		}
	}
	// ȥͰ����
	for (int i = 0; i < words.size(); i++) {
		if (words[i] >= 'a' && words[i] <= 'z') {
			if (--lowerLetter[words[i] - 'a'] < 0) {
				cout << "NO";
				return 0;
			}
		} else if (words[i] >= 'A' && words[i] <= 'Z') {
			if (--upperLetter[words[i] - 'A'] < 0) {
				cout << "NO";
				return 0;
			}
		}
	} 
	cout << "YES";
	return 0;
} 
