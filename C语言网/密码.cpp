#include <iostream>
#include <algorithm>
using namespace std;
bool ischar(char c) {
	return c == '~' || c == '!' || c == '@'
	|| c == '#' || c == '$' || c == '%' || c == '^';
}
int main() {
	int T;
	string str;
	bool f1, f2, f3, f4;
	cin >> T;
	while (T--) {
		cin >> str;
		f1 = f2 = f3 = f4 = false;
		for (string::iterator it = str.begin(); it != str.end(); ++it) {
			if (islower(*it)) f1 = true;
			if (isupper(*it)) f2 = true;
			if (isdigit(*it)) f3 = true;
			if (ischar(*it)) f4 = true;
		}
		if (f1 && f2 && f3 || f1 && f2 && f4 || f2 && f3 && f4) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
