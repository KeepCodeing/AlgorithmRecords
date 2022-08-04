#include <iostream>
using namespace std;

// 1e8的数据埃氏筛居然也可以过...不过题解的埃氏筛和一般写法的埃氏筛有所不同，其是直接枚举的i*i，这样可能更能
// 提升效率罢 
// 差点坠毁w，其实这个是改造了下埃氏筛，它求得是非质数的数量，然后总数量减去非质数
// 的数量就是质数的数量... 

// 依次枚举i会超时一个点，如果枚举i*i就能在2s内跑完1e8的数据，可以看做是提升了效率 

const int N = 1e8 + 10;
bool primes[N];
int main() {
	int n;
	cin >> n;
	int res = n - 1;
	primes[0] = primes[1] = true;
	// 变动1:这里的i<=n改成了i * i <= n，可能把时间优化成log了... 
	for (int i = 2; i * i <= n; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			// 变动2:这里判断了下当前数是不是质数，不是质数
			// 才能使res进行自减，是质数进行自减会造成答案错误 
			if (!primes[j]) {
				primes[j] = true;
				res--;	
			}
			
		}
	}
	// for (int i = 0; i < n; i++) if (!primes[i]) cout << i << ' ';
	cout << res;
	return 0;
}
