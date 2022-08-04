#include <iostream>
using namespace std;

// ±©¡¶º”∞£ œ…∏

bool primes[10001];
void initPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 10000; i++) {
		if (!primes[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				primes[j] = true;
			}	
		}
	}
}
int main() {
	initPrimes();
	int n;
	cin >> n;
	for (int i = 4; i <= n; i+=2) {
		//if (i % 2 == 0) {
		for (int j = 0; j <= i; j++) {
			if (!primes[j]) {

				if (!primes[i - j]) {
					cout << i << '=' << j << '+' << i - j << endl;
					break;
				}
			}
		}	
		//}
	}
	
	return 0;
} 
