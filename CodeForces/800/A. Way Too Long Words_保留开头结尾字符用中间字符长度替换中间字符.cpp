#include <iostream>
using namespace std;
int main() {
	int n, sLen;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		sLen = str.size();
		// 直接输出，保留还要把长度转为字符串..，另外这里是严格大于10，所以应该是>号... 
		if (sLen > 10) cout << str[0] << sLen - 2 << str[sLen - 1] << endl;
		else cout << str << endl;
	}
	return 0;
}
