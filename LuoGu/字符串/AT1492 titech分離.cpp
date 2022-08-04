#include <iostream>
#include <map>
using namespace std;

// WA了一堆点，果然不是迫真桶排... 

map<char, float > mp;
bool checker(char c) {
	return c != 't' && c !='i' && c != 'e' && c != 'c' && c != 'h';
}
int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if (checker(str[i])) {
			cout << "No" << endl;
			return 0;
		}
		mp[str[i]] += str[i] != 't' ? 1.0 : .5;
	}
	
	for (map<char, float >::iterator it = mp.begin(); it != mp.end(); it++) {
		if (mp['t'] != it->second) {
			cout << "No" << endl;
			return 0;
		}
		//cout << it->first << ' ' << it->second << endl;
	}
	cout << "Yes" << endl;
	return 0;
}
