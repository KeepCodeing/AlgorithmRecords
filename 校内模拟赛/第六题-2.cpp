#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (str[i] >= 'x' && str[i] <= 'z') str[i] = 'c' - ('z' - str[i]);
		else str[i] += 3;
	}
	cout << str;
	return 0;
}
