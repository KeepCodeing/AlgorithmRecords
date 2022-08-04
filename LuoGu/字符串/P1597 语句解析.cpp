#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string > vec;
map<char, char > mp;
int main() {
	string str, temp;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (str[i] == ';') {
			vec.push_back(temp);
			temp = "";
		} else {
			temp += str[i];
		}
	}
	char ct, nt, a = '0', b = '0', c = '0';
	for (int i = 0; i < vec.size(); i++) {
		// 写的怀疑智商w，总之过了w.. 
		ct = vec[i][0], nt = vec[i][3];
		if (ct == 'a') {
			if (nt != 'a' && nt != 'b' && nt != 'c') a = nt;
			else if (nt == 'a') a = a;
			else if (nt == 'b') a = b;
			else if (nt == 'c') a = c;
		} else if (ct == 'b') {
			if (nt != 'a' && nt != 'b' && nt != 'c') b = nt;
			else if (nt == 'a') b = a;
			else if (nt == 'b') b = b;
			else if (nt == 'c') b = c;
		} else if (ct == 'c') {
			if (nt != 'a' && nt != 'b' && nt != 'c') c = nt;
			else if (nt == 'a') c = a;
			else if (nt == 'b') c = b;
			else if (nt == 'c') c = c;
		}
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}
