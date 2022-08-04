#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 多重背包求方案数

const int N = 1010;
bool primes[N];
vector<int > vec;
void getPrime() {
	for (int i = 2; i <= N; i++) {
		if (primes[i]) continue;
		vec.push_back(i); 
		for (int j = i *2; j <= N; j += i) {
			primes[j] = true;
		}
	}
}
// 没开long long坠毁了一次ww 
long long f[N];
int main() {
	getPrime();
	int n;
	cin >> n;
	int idx = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
	f[0] = 1;
	// 物品个数就是小于等于该数的质数数量，注意这里要加上这个数自己 
	for (int i = 0; i <= idx; i++) {
		// 物品价值就是当前质数 
		for (int j = vec[i]; j <= n; j++) {
			f[j] += f[j - vec[i]];
		}
	}
	cout << f[n];
	return 0;
} 
