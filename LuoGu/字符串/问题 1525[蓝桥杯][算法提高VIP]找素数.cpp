#include <iostream>
using namespace std;

// 质素筛，本来以为还要前缀和的，但是只有一次询问
// 不过区间长度很大，可能还要做下离散化，但实际上这些数字是连在一起的
// 所以可以用减去l的方式来获得较小的下标 
 
bool *primes; 

void getPrimes(int l, int r) {
	primes[0] = primes[1] = true;
	for (int i = l; i <= 1000; i++) {
		if (primes[i - l]) continue;
		for (int j = i * 2; j <= 1000; j += i) {
			primes[j] = true;
		}
	}
}

int main() {
	int l, r;
	cin >> l >> r;
	primes = new bool[r - l + 10];
	fill(primes, primes + r - l + 10, false);
	getPrimes(l, r);
	for (int i = 0; i <= 1000; i++) {
		if (!primes[i]) cout << i + l << ' ';
	}
	delete[] primes;
	return 0;
} 
