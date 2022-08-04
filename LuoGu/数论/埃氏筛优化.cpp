#include <iostream>
#include <cmath>
using namespace std;

// 首先，枚举只用枚举到sqrt(n)，因为大于sqrt(n)的数可能会被筛过，比如说：sqrt(100) = 10，不难发现我们从20枚举所筛去的数一定被5筛过 
// 另外对于筛过的数（质数）就不用筛了，这种优化可以达到n*loglogn的复杂度 
// 这种筛法虽然能够更快速的筛出范围内的质数，但是不能用来统计范围内的素数的数量，统计数量必须扫描整个范围内的数，也就是朴素
// 的埃氏筛才能筛数量 

const int N = 1e7;
bool primes[N];
int main() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			primes[j] = true;
		}
	}
	for (int i = 0; i < 1e3; i++) if (!primes[i]) {
		cout << i << endl;
	}
	return 0;
}
