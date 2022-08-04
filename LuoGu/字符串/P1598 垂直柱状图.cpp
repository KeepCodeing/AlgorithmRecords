#include <iostream>
using namespace std;

// 用到一个新函数，getline，该函数接受两个参数，输入流和string对象，可以读入一整行字符串 

// 用桶来统计字符数 
int bucket[26];
int main() {
	string str[4];
	// 出现次数最多的字符决定着输出空格数 
	int maxLen = -1;
	int index;
	for (int i = 0; i < 4; i++) {
		getline(cin, str[i]);
		for (int j = 0; j < str[i].size(); j++) {
			index = str[i][j] - 'A';
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') bucket[index]++;
			if (bucket[index] > maxLen) maxLen = bucket[index];
		}
	}
	int temp = maxLen;
	for (int i = 0; i < temp; i++) {
		for (int j = 0; j < 26; j++) {
			if (bucket[j] >= maxLen) cout << '*';
			else cout << ' ';
			if (j != 25) cout << ' ';
		}
		cout << endl;
		if (i == temp - 1) {
			for (char k = 'A'; k <= 'Z'; k++) {
				cout << k;
				if (k != 'Z') cout << ' ';
			}
		}
		maxLen--;
	}
	return 0;
}
