#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (str[i] <= 'Z' && str[i] >= 'A' || str[i] <= 'z' && str[i] >= 'a') {
			if (str[i] == 'z' || str[i] == 'Z') str[i] = str[i] - 25;
			else str[i] += 1;
		}
	}
	cout << str;
	return 0;
}
