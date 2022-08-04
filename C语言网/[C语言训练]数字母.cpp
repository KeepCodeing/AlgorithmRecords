#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size(), cnt = 0;
	for (int i = 0; i < sLen; i++) {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') cnt++;
	}
	cout << cnt;
	return 0;
}
