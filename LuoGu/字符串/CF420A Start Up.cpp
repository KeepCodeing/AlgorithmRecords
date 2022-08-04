#include <iostream>
#include <algorithm>
using namespace std;

// 痿到现在，没想到这个题真的让其start up了（指做题）... 

// N不是镜像字符（动脉瘤破裂） 
// A H I M N O T U V W X Y
bool checker(char s) {
	//return s!='A'&&s[i]!='H'&&s[i]!='V'&&s[i]!='I'&&s[i]!='M'&&s[i]!='W'&&s[i]!='O'&&s[i]!='T'&&s[i]!='U'&&s[i]!='X'&&s[i]!='Y';
}
int main() {
	string str;
	cin >> str;
	// 首先判断下是不是回文，然后判断下该字符串是否只存在镜像字符串
	string temp = str;
	int l = 0, r = str.size() - 1;
	while (l < r) swap(temp[l++], temp[r--]);
	cout << temp;
	if (temp != str) cout << "NO" << endl;
	else {
		for (int i = 0; i < str.size(); i++) {
			if (!checker(str[i])) {
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
	}
	return 0;
} 
