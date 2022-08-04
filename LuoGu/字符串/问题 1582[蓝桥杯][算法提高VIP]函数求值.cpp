#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;

	cout << (count(str.begin(), str.end(), '1') % 20123 + count(str.begin(), str.end(), '2') % 20123); 	
}
