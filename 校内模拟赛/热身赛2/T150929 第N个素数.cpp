#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
const int N = 5e6 + 10;
bool primes[N];
void getprimes() {
	int cnt = 0;
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!primes[i]) {
			cout << ++cnt << '=' << i << endl;
			if (cnt == 202020) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	getprimes();
	//cout << 2780083 << endl;
	return 0;
}
