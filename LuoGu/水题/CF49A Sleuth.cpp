#include <iostream>
using namespace std;

// ˮ���ʮ�ߵ�...Ԥ�е�77�����п���w 

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
