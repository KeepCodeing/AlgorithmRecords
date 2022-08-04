#include <iostream>
#include <algorithm>
using namespace std;

// 热身题 
// 然而做了半天都没想明白怎么去最后一个+... 

int main() {
	char m;
	int sLen, oneCnt, cnt = 0;
	string str;
	char temp;
	cin >> m >> str;
	sLen = str.size();
	oneCnt = sLen - count(str.begin(),  str.end(), '0');
	for (int i = sLen - 1; i >= 0; i--) {
		temp = str[sLen - i - 1];
		if (temp != '0') {
			cnt++;
			cout << temp << '*' << m << '^' << i;
			// 判断是不是最后一个非0字符 
			if (cnt != oneCnt) cout << '+';
		}
	}
	return 0;
}
