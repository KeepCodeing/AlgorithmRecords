#include <iostream>
using namespace std;

// 水题第十四弹...Comfortably Numb 

int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (islower(str[i])) cnt++;
		else cnt--;
	}
	for (int i = 0; i < str.size(); i++) {
		if (cnt >= 0) str[i] = tolower(str[i]);
		else str[i] = toupper(str[i]);
	}
	cout << str;
	return 0;
}
