#include <iostream>
using namespace std;
bool checker(char a, char l, char r) {
	return l <= a && a <= r;
}
int main() {
	string str;
	cin >> str;
	int low, high;
	low = high = 0;
	for (int i = 0; i < str.size(); i++) {
		if (checker(str[i], 'a', 'z')) low++;
		else high++;
	}
	// ��Сд��ĸһ���໻��Сд��ĸ 
	if (low >= high) {
		for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
	} else {
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
	}
	cout << str << endl;
	return 0;
}
