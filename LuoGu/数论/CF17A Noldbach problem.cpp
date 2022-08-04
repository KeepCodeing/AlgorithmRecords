#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 然而并没有完全理解题意ww，题目的意思是[2, n]内的任意两个相邻的素数之和+1也是素数，并且这些素数的个数大于等于
// k，就输出YES，否则输出NO 

const int N = 1010;
bool primes[N];
vector<int > vec;
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= N; i++) {
		if (primes[i]) continue;
		vec.push_back(i); 
		for (int j = i * 2; j <= N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getPrimes();
	int n, k;
	cin >> n >> k;
	int ans = 0, temp = 0;
	int vLen = vec.size();
	for (int i = 0; i < vLen - 1; i++) {
		// 统计[2, n]区间内任意两个相邻的素数和并且判断这个和是不是素数 
		temp = vec[i] + vec[i + 1] + 1;
		if (temp > n) break;
		if (!primes[temp]) ans++;
	}
	if (ans >= k) cout << "YES";
	else cout << "NO";
	return 0;
}
