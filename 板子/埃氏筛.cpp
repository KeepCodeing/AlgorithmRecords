#include <iostream>
#define endl '\n'
using namespace std;

const int N = 1e6 + 10;
bool primes[N];

void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < N; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j < N; j += i) {
			primes[j] = true;
		}
	}
	for (int i = 0; i <= 100; i++) {
		if (!primes[i]) cout << i << endl;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	getPrimes();
	return 0;
}
