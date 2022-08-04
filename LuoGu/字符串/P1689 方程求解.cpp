#include <iostream>
using namespace std;

// 可能会出现多余空格，所以还要处理下空格，数据有点大，可能要用long 
// 坠毁...
 
long strToNum(string str) {
	long num = 0;
	int fh = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			fh *= -1;
			continue;
		} else if (str[i] == '+') {
			continue;
		}
		num = num * 10 + (int)(str[i] - '0');
	} 
	num *= fh;
	return num;
}
int main() {
	string temp, str;
	getline(cin, temp);
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] != ' ') str += temp[i];
	}
	// 取到=右边的字符串，判断下其是？还是数字 
	int index = str.find('=');
	long ans = 0;
	string right = str.substr(index + 1);
	string left = str.substr(0, index);
	int t = left.find('-') == left.npos ? left.find('+') : left.find('-');
	// 如果等号右边是未知数，直接计算结果即可 
	if (right == "?") {
		// 数据给出的范围为>=0，所以第一个数不可能为负
		ans = strToNum(left.substr(0, t)) + strToNum(left.substr(t) );
	} else {
		// 如果=右边不是?，把它转换成数字
		long r = strToNum(right);
		string l_l, l_r;
		l_l = left.substr(0, t);
		l_r = left.substr(t);
		if (l_l != "?") {
			// 模拟交换律 
			if (l_r == "-?") {
				ans = (-(strToNum(l_l) - r)) * -1;
			} else {
				ans = (-(strToNum(l_l) - r));
			}
		} else {
			ans = r - strToNum(l_r);
		}
	}
	cout << ans;
	return 0;
}
