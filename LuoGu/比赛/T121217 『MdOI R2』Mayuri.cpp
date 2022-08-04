#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int a, b;
	string s;
	cin >> a >> b;
	cin >> s;
	if (a == 10) cout << -1;
	else if (s.size() == 1) {
		int t = s[0] - '0';
		if (t == 1) cout << a;
		else cout << 1;
	} else {
		if (s == "00") {
			cout << a - 1 << a - 1;
		} else if (s == "10") {
			cout << a << a - 1;
		} else if (s == "11") {
			cout << a << 0;
		} else {
			
		}
	}
	return 0;
}
