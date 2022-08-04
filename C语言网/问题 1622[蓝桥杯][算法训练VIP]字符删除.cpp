#include <iostream>
using namespace std;
int main() {
	string str;
	char c;
	cin >> str;
	cin >> c;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != c) cout << str[i];;
	}
	return 0;
}
