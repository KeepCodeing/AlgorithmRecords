#include <iostream>
using namespace std;

// 奇妙，这个题实际是用前缀和做，但是本five感觉也可用质数筛做 
// 太低效，坠毁了ww 

bool primes[100010];
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 100010; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= 100010; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getPrimes();
	int n;
	cin >> n;
	int l, r;
	int cnt;
	while (n--) {
		cin >> l >> r;
		cnt = 0;
		for (int i = l; i <= r; i++) {
			if (i % 2 != 0 && !primes[i] && !primes[(i + 1) >> 1]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	// for (int i = 0; i < 100; i++) if (!primes[i]) cout << i << endl;
	return 0;
}
