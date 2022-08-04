#include <iostream>
using namespace std;
int main() {
	int s, v;
	cin >> s >> v;
	int cnt = 1;
	while (v < s) {
		v *= cnt;
		cnt++;
	}
	cout << cnt - 1;
	return 0;
}
