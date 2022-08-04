#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	string str;
	cin >> n >> str;
	int l = 0, r = n - 1;
	while (l < r) swap(str[l++], str[r--]), cout << str << endl;
	cout << endl << str;
	return 0;
}
