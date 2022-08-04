#include <iostream>
using namespace std;

// 从后往前截取字符串然后到另一个字符中查找，如果有
// 则第一次出现的字符串绝对是最长的 

int main() {
	string a, b;
	string aTemp1, aTemp2;
	int minLen = 0, index = 0;
	cin >> a >> b;
	for (int i = min(a.size(), b.size()); i > 0; i--) {
		// 从后往前截取 
		aTemp1 = a.substr(0, i);
		// 从当前下标往后截取，数据水，交了两次没写这个
		// 居然都能有90w 
		aTemp2 = a.substr(index);
		if (b.find(aTemp1) != b.npos) {
			minLen = aTemp1.size();
			break;
		} else if (b.find(aTemp2) != b.npos) {
			minLen = aTemp2.size();
			break;
		}
		index++;
	}
	cout << minLen;
	return 0;
}
