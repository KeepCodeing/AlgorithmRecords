#include <iostream>
using namespace std;
int main() {
	int n, minNum = 1001, maxNum = -1, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (minNum > t) minNum = t;
		if (maxNum < t) maxNum = t;
	}
	cout << maxNum - minNum;
	return 0;
}
