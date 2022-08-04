#include <iostream>
using namespace std;
// 我谔谔，是要求n个素数，不是说上限是n（无能） 
bool primes[1500000];
void getPrimes(int n) {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 1500000; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= 1500000; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	int n;
	cin >> n;
	getPrimes(n);
	unsigned long long ans = 1;
	int cnt = 0;
	for (int i = 0; i <= 1500000; i++) {
		if (!primes[i]) {
			++cnt;
			if (cnt > n) break;
			// 池沼了，把乘积又改成和WA了ww 
			ans *= i;
			ans %= 50000;
		}
	}
	cout << ans;
	return 0;
}
