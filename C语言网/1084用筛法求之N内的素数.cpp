#include <iostream>
using namespace std;
bool *primes;
int main() {
	int n;
	cin >> n;
	primes = new bool[n + 1];
	fill(primes, primes + n + 1, false);
	primes[0] = primes[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!primes[i]) {
			for (int j = i * 2; j <= n; j += i) {
				primes[j] = true;
			}	
		}
	}
	for (int i = 0; i <= n; i++) {
		if (!primes[i]) cout << i << endl;
	}
	delete[] primes;
	return 0;
}
