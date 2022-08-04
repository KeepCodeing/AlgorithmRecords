#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	if (str.substr(0, 3) != "MDA") {
		cout << "1 1 1 1 1";
		return 0;
	}
	int sLen = str.size() - 1;
	char wh;
	for (int i = sLen; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			wh = str[i];
			break;
		}
	}
	if (wh == '1' || wh == '9') {
		cout << "1 0 0 0 0";
	} else if (wh == '2' || wh == '8') {
		cout << "0 1 0 0 0";
	} else if (wh == '3' || wh == '7') {
		cout << "0 0 1 0 0";
	} else if (wh == '4' || wh == '6') {
		cout << "0 0 0 1 0";
	} else {
		cout << "0 0 0 0 1";
	}
	return 0;
}
