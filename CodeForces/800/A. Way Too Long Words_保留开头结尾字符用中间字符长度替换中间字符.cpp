#include <iostream>
using namespace std;
int main() {
	int n, sLen;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		sLen = str.size();
		// ֱ�������������Ҫ�ѳ���תΪ�ַ���..�������������ϸ����10������Ӧ����>��... 
		if (sLen > 10) cout << str[0] << sLen - 2 << str[sLen - 1] << endl;
		else cout << str << endl;
	}
	return 0;
}
