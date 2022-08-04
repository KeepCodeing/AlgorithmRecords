#include <iostream>
using namespace std;
bool primes[2000010];
void getPrimes(int n) {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= n; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	int n;
	cin >> n;
	getPrimes(n);
	long ans = 0;
	for (int i = 2; i <= n; i++) {
		if (!primes[i]) ans += i;
	}
	cout << ans;
	return 0;
}
