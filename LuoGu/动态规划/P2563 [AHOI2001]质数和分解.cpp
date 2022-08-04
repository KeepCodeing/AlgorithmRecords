#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 完全背包求方案数,DP的题目背景变化很大，基本换一个背景就有种新题目的感觉了
// 这个题也不例外，对于背包问题而言主要是找准什么是背包容积，什么是物品价值，什么是
// 物品代价...

// 这个题还要注意下素数的特判，素数自己就能组成自己，所以不管怎么样素数的组成方案总要多一个 

typedef long long LL;
const int N = 220;
LL f[N];
vector<int > primes;
bool prs[250];
void getPrimes() {
	fill(prs, prs + 250, false);
	prs[0] = prs[1] = true;
	for (int i = 2; i <= 210; i++) {
		if (prs[i]) continue;
		primes.push_back(i); 
		for (int j = i * 2; j <= 210; j += i) {
			prs[j] = true;
		}
	}
}
int findNum(int num) {
	return lower_bound(primes.begin(), primes.end(), num) - primes.begin();
}
int main() {
	getPrimes();
	// for (int i = 0; i < primes.size(); i++) cout << primes[i] << endl;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int num;
	while (cin >> num) {
		fill(f, f + N, 0);
		f[0] = 1;
		for (int i = 0; i < findNum(num); i++) {
			for (int j = primes[i]; j <= num; j++) {
				f[j] += f[j - primes[i]];
			}
		}
		// 是素数就能多一种组成方案 
		cout << f[num] + !prs[num] << endl;
	}
	return 0;
} 
