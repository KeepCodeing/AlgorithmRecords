#include <iostream>
#define endl '\n'
using namespace std;
const int N = 10000 + 10;
bool primes[N];
void getPrimes() {
	int res = 0;
	for (int i = 2; i <= 10000; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= 10000; j += i) {
			primes[j] = true;
		
		}
	}
	for (int i = 2; i <= 10000; i++) {
		if (!primes[i]) res++;
	}
	cout << res;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	getPrimes();
	return 0;
}
