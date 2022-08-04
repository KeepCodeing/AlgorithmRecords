#include <iostream>
#include <cmath>
using namespace std;
const int N = 32767 + 10;
bool primes[N];
void getprime() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	int n, cnt = 0;
	cin >> n;
	getprime();
	// 脑子抽了，没想到怎么去重，明明正式枚举之前也枚举过数对的...，主要是范围理解错了，之前写的N，也就是把所有
	// 素数都枚举遍，然后就出现了cnt = n * 2 - 1的情况，这就比较无语w，因为出现了重复数对..甚至想用set去重w... 
	for (int i = 1; i <= n / 2; i++) {
		// 如果当前数是一个素数，判断n - 这个素数是不是还是个素数... 
		if (!primes[i] && !primes[n - i]) cnt++; 
	}
	cout << cnt;
	return 0;
}
