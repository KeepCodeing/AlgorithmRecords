#include <iostream>
using namespace std;

// 水题第十七弹...预感第77弹都有可能w 

int main() {
	string str, res = "NO";
	getline(cin, str);
	int sLen = str.size();
	while (--sLen) if (isalpha(str[sLen])) break;
	char temp = tolower(str[sLen]);
	if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'y') res = "YES";
	cout << res;
	return 0;
}
