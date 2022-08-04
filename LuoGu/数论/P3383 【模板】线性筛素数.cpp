#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1000000000 + 10;
bool primes[N];
vector<int > vec;
void getprime(int n) {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= n; i++) {
		if (primes[i]) continue;
//		cout << i << endl;
//		vec.push_back(i); 
		for (LL j = i * i; j <= n; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	getprime(n);
	while (m--) {
		scanf("%d", &t);
		printf("%d\n", vec[t - 1]);
	}
	return 0;
}
