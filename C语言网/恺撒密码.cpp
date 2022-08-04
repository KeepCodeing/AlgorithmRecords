#include <iostream>
using namespace std;
string tb = "VWXYZABCDEFGHIJKLMNOPQRSTU";
void printAns(string str) {
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		if (isalpha(*it)) *it = tb[*it - 'A'];
		cout << *it;
	}
	cout << endl;
}
// C语言网AC，洛谷爆零，蒙古...（大概是getline在操作系统下的区别..） 
int main() {
	string str;
	while (true) {
		getline(cin, str);		
		if (str == "ENDOFINPUT") break;
		if (str == "START") {
			while (true) {
				getline(cin, str);
				if (str == "END") break;
				printAns(str);
			}
		}
	}
	return 0;
}
