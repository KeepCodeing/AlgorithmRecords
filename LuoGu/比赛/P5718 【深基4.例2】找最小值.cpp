#include <iostream>
using namespace std;
int main() {
	int n, minNum = 1001, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (minNum > t) minNum = t;
	}
	cout << minNum;
	return 0;
}
