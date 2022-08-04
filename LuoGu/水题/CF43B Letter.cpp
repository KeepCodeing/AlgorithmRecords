#include <iostream>
using namespace std;

// 摸了一天的图论，刷点水题.. 

// 桶，题目说区分大小写，因此这里搞了两个桶 
int upperLetter[26], lowerLetter[26];
int main() {
	string str, words;
	getline(cin, str);
	getline(cin, words);
	// 入桶
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			lowerLetter[str[i] - 'a']++;
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			upperLetter[str[i] - 'A']++;
		}
	}
	// 去桶里找
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
