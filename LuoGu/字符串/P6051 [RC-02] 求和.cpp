#include <iostream>
#include <sstream>
using namespace std;

// 字符串模拟题，没想到居然有普及难度
// 多考虑的一点是某个字符前面的间隔符是否表明这个字符是个负数
// 判断方法就是如果类似**-1234，那这个数就是负数，否则如123-1234
// 那这个数就不是负数。
// 如何判断是否是负数
// 当str[i - 1] == '-' && str[i - 2] != 数字，那这个数就不是负数，否则
// 这个数就是负数 

bool isNum(char c) {
	return c >= '0' && c <= '9';
}
int main() {
	string str;
	while (getline(cin, str)) {
		str += "*";
		int sLen = str.size();
		bool flag = true, isAns = false;;
		int res = 0;
		string temp;
		for (int i = 0; i < sLen; i++) {
			if (isNum(str[i])) {
				if (flag) {
					flag = false;
					if (i != 0 && str[i - 1] == '-') {
						string c = "-";
						if (i >= 2 && isNum(str[i - 2])) c = "";
						temp += c;
					}
				}
				temp += str[i];
			} else {
				flag = true;
				if (temp != "") {
					stringstream ss;
					ss << temp;
					int t;
					ss >> t;
					res += t;
					temp = "";
					isAns = true;
				}
			}
		}
		if (isAns) cout << res << endl;
	}
	return 0;
}
