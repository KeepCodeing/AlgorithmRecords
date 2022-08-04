#include <iostream>
using namespace std;
int main() {
	string str;
	int cnt = 0;
	while(cin >> str) {
		cnt += str.size();
	}
	cout << cnt;
	return 0;
}
