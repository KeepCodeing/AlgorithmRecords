#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	cout << sLen << endl;
	for (int i = 0; i < sLen; i++) cout << str[i] << ' ';
	cout << endl;
	for (int i = sLen - 1; i >= 0; i--) cout << str[i];
	return 0;
}
