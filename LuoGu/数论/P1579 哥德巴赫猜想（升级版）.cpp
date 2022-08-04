#include <iostream>
using namespace std;

// 先枚举所有范围内素数，再暴力求解 

bool arr[20001];
int primes[20001];
int main() {
	int cnt = 0;
	int num;
	cin >> num;
	arr[0] = arr[1] = true;
	for (int i = 2; i <= 20000; i++) {
		if (!arr[i]) {
			primes[cnt++] = i;
			for (int j = i * 2; j <= 20000; j += i) {
				arr[j] = true;
			}
		}
		
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			for (int k = 0; k < cnt; k++) {
				if (primes[i] + primes[j] + primes[k] == num) {
					cout << primes[i] << ' ' << primes[j] << ' ' << primes[k];
					return 0;
				}
			}
		}
	}
	return 0;
}
