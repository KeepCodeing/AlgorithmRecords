#include <iostream>
using namespace std;
int main() {
	int n;
	int r = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) r += i;
	cout << r;
	return 0;
}
