#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		cout << str[i];
		if (i != sLen - 1) cout << ' ';
	}
	return 0;
}
