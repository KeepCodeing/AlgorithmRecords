#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
string rev(string str) {
	int l = 0, r = str.size() - 1;
	while (l < r) swap(str[l++], str[r--]);
	return str;
}
int main() {
	string a, b;
	cin >> a >> b;
	stringstream ss;
	int a1, b1;
	ss << a, ss >> a1, ss.clear();
	ss << rev(b), ss >> b1, ss.clear();
	cout << a1 + b1;  
	return 0;
}
