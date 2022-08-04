#include <iostream>
using namespace std;
char cs[30];
int main() {
	int n, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cs[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (cs[i] != cs[i + 1]) cnt++;
	}
	cout << cnt + 1;
	return 0;
}
