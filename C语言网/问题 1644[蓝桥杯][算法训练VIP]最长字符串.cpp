#include <iostream>
using namespace std;
int main() {
	int n = 5;
	int maxLen = -1;
	string res;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		// ������ĵط���size()��������ֱ�Ӻ����ζԱ� 
		int sLen = str.size();
		if (sLen > maxLen) {
			maxLen = str.size();
			res = str;
		}
	}
	cout << res;
	return 0;
} 
