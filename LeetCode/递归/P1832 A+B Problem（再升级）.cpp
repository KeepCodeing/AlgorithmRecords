#include <iostream>
using namespace std;
// bool primes[1010];
bool primes[1010];
int getPrimes(int n) {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 1010; i++) {
		if(!primes[i]) {
			for (int j = i * 2; j <= 1010; j += i) {
				primes[j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if(!primes[i]) cnt++; 
	}
	return cnt;
}
int ans = 0;
//void dfs(int level, int deepth, int num) {
//	if (num <= 0 || level > 410) {
//		if (num == 0) ans++;
//		return;
//	}
//	for (int i = level; i < deepth; i++) {
//		if (num - primes[i] < 0) continue;
//		dfs(i, deepth, num - primes[i]);
//	}
//}
int main() {
	int n;
	cin >> n;
	// ÍêÈ«±³°ü...
	for (int i = 2; i <= getPrimes(n); i++) {
		for (int j = )
	} 
	// dfs(0, n, n);
	// cout << ans;
	return 0;
}
