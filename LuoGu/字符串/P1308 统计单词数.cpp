#include <iostream>
using namespace std;
string strToLower(string str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
	}
	return str;
}
// td
//   Td tLWCsrmt
// ���ݱȽϿӣ����жϿո������ 
int main() {
	string target;
	cin >> target;
	int cnt = 0, firstIndex = -1;
	target = strToLower(target);
	string strs;
	while (cin >> strs) {
		// ���û���ֹ���ͳ��λ�� 
		if (cnt == 0) firstIndex++;
		if (target == strToLower(strs)) cnt++;
	}
	if (cnt == 0) cout << -1;
	else cout << cnt << ' ' << firstIndex;
	return 0;
}
