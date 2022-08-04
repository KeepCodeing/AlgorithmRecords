#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	int s, st;
	cin >> s >> st;
	for (int i = s; i < sLen; i += st) cout << str[i];
	return 0;
}
