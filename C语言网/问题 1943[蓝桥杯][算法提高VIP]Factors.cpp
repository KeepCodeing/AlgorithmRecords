#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
void getPrime(LL x, vector<int >& primes) {
	for (LL i = 2; i <= x / i; i++) {
		while (!(x % i)) {
			primes.push_back(i);
			x /= i; 
		}
	}
	if (x > 1) primes.push_back(x);
	sort(primes.begin(), primes.end()); 
}
int getPer(vector<int >& primes) {
	LL cnt = 0;
	do {
		cnt++;
	} while (next_permutation(primes.begin(), primes.end()));
	return cnt;
}
int main() {
	LL n;
	while (cin >> n) {
		for (int i = n + 1;; i++) {
			vector<int > primes;
			getPrime(i, primes);
			if (getPer(primes) == n) {
				cout << n << ' ' << i << endl;
				break;
			}
		}
	}
	return 0;
}
