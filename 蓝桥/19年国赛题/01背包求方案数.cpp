#include <iostream>
#include <cmath>
using namespace std;

// 看别人博客没能一眼发现是个01背包...先打个素数表，然后开long long
// 套方程完事... 

typedef long long LL;
const int N = 3000, M = 2019;
bool primes[N];
LL f[N];
void getprimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getprimes();
	f[0] = 1;
	// 背包模型快忘光了（指细节），感觉要复习下了（使命感）... 
	for (int i = 0; i < N; i++) {
		if (primes[i]) continue;
		for (int j = M; j >= i; j--) {
			f[j] += f[j - i];
		}
	}
	cout << f[2019];
	return 0;
}
