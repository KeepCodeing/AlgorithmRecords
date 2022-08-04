#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	cout << count(str.begin(), str.end(), '1');
	return 0;
}
