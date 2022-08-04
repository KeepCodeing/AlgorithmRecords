#include <iostream>
using namespace std;
long long res[5010];
int dg(int n) {
	if (n <= 1) return 1;
	if (n == 2) return 2;
	if (res[n]) return res[n];
	res[n] = dg(n - 1) + dg(n - 2);
	return res[n];
}
int main() {
	int n;
	cin >> n;
	cout << dg(n);
	return 0;
}
