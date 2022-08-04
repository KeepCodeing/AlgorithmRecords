#include <iostream>
#include <cstdio> 
using namespace std;
int main() {
	string words;
	getline(cin, words);
	char op = getchar();
	if (op == 'D') {
		getchar();
		char c = getchar();
		if (words.find(c) == words.npos) {
			cout << "no exist";
			return 0;
		}
		// 第二个参数是要删除多少字符，不指定默认把后面全删除 
		words.erase(words.find(c), 1);
		cout << words; 
	} else {
		getchar();
		char a, b;
		scanf("%c %c", &a, &b);
		if (op == 'I') {
			if (words.find_last_of(b) == words.npos) {
				cout << "no exist";
				return 0;
			}
			cout << words.substr(0, words.find_last_of(b));
			cout << a;
			cout << words.substr(words.find_last_of(b));
		} else {
			if (words.find(a) == words.npos) {
				cout << "no exist";
				return 0;
			}
			for (int i = 0; i < words.size(); i++) {
				if (words[i] == a) words[i] = b;
			}
			cout << words;
		}
	}
	return 0;
}
