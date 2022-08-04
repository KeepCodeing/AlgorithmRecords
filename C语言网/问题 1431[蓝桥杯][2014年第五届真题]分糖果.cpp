#include <iostream>
using namespace std;
int *boys;
int main() {
	int n;
	cin >> n;
	boys = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> boys[i];
	
	for (int i = 2; i <= n; i++) {
		boys[i] /= 2;
		boys[i - 1] += boys[i];
		if (boys[i - 1] % 2 != 0) boys[i - 1] += 1;
		if (boys[i] % 2 != 0) boys[i] += 1;
	}
	// 3 1 4
	// 3 3 2
	// 4 4 2
	
	// 6 2 2
	// 6 3 1
	// 6 4 2
	
	// 8 2 2
	// 8 4 1
	// 8 4 2
	
	delete[] boys;
	return 0;
}
