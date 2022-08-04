#include <iostream>
using namespace std;
bool che(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
	string str;
	cin >> str;
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (che(str[i])) {
			cout << i + 1;
			flag = false;
			break;
		}
	}
	if (flag) cout << 0;
	return 0;
}
