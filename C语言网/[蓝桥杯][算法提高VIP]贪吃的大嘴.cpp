#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 55, M = 20000 + 10;
struct cookies {
	int val, k;
	cookies(int val, int k) : val(val), k(k) {};
	cookies() {};
} ck[N];
vector<cookies > vec;
int f[M];
int main() {
	int n, m, val, k;
	cin >> m >> n;
	while (n--) {
		cin >> val >> k;
		// 二进制优化的板子，注意可以直接在线处理... 
		for (int i = 1; i <= k; i <<= 1) {
			// 这里将物品重量设置为美味程度，将价值设置为物品个数，然后跑01背包就行... 
			vec.push_back(cookies(val * i, i));
			k -= i;
		}
		if (k > 0) vec.push_back(cookies(val * k, k)); 
	}
	// 注意初始化，因为要求的是最小值，所以一开始就要设置为最大值，但是光设置最大值没有用，因为
	// 最开始的那个状态也是个最大值，所以要把最开始的状态特殊处理为0.. 
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = m; j >= vec[i].val; j--) {
			// 01背包，注意这里的物品价值变成了物品个数.. 
			f[j] = min(f[j], f[j - vec[i].val] + vec[i].k);
		}
	}
	if (f[m] != 0x3f3f3f3f) cout << f[m];
	else cout << "><";
	return 0;
}
