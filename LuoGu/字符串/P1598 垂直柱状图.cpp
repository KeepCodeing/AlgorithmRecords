#include <iostream>
using namespace std;

// �õ�һ���º�����getline���ú�������������������������string���󣬿��Զ���һ�����ַ��� 

// ��Ͱ��ͳ���ַ��� 
int bucket[26];
int main() {
	string str[4];
	// ���ִ��������ַ�����������ո��� 
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
