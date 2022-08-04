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
// 数据比较坑，得判断空格的问题 
int main() {
	string target;
	cin >> target;
	int cnt = 0, firstIndex = -1;
	target = strToLower(target);
	string strs;
	while (cin >> strs) {
		// 如果没出现过就统计位置 
		if (cnt == 0) firstIndex++;
		if (target == strToLower(strs)) cnt++;
	}
	if (cnt == 0) cout << -1;
	else cout << cnt << ' ' << firstIndex;
	return 0;
}
