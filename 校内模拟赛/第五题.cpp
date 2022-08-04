#include <iostream>
using namespace std;
bool isY(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	int a, b, c, d;
	a = b = c = d = 0;
	for (int i = 0; i < sLen; i++) {
		if (!isY(str[i])) a++;
		else break;
	}
	if (!a) {
		cout << "no";
		return 0;
	}
	for (int i = a; i < sLen; i++) {
		if (isY(str[i])) b++;
		else break;
	}
	if (!b) {
		cout << "no";
		return 0;
	}
	for (int i = a + b; i < sLen; i++) {
		if (!isY(str[i])) c++;
		else break;
	}
	if (!c) {
		cout << "no";
		return 0;
	}
	for (int i = a + b + c; i < sLen; i++) {
		if (isY(str[i])) d++;
		else break;
	}
	if (!d) {
		cout << "no";
		return 0;
	}
	if (a + b + c + d != sLen) {
		cout << "no";
		return 0; 
	}
	cout << "yes";
	return 0;
}
