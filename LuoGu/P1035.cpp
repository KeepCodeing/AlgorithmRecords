#include <iostream>
using namespace std;
int main() {
	int k = 1, n;
	double sn = 0;
	cin >> n;
	while (1) {
		sn = sn + 1.0 / k;
		if (sn > n) break;
		k++;
	}
	cout << k;
	return 0;
}
