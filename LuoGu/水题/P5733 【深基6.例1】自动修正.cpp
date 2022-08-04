#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		str[i] = str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i];
	}
	cout << str;
	return 0;
}
