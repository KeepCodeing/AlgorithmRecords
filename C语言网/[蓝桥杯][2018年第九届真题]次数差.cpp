#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	int mx = -1, mn = 10000, t;
	for (char i = 'a'; i <= 'z'; i++) {
		t = count(str.begin(), str.end(), i);
		if (t != 0) mx = max(mx, t), mn = min(mn, t);
	}
	cout << mx - mn;
	return 0;
}
