#include <iostream>
using namespace std;

// 裸完全背包... 
// 太谔谔了，原来f[j] = f[j - nums[i]] % mod 是错误的，必须算完再模... 

const int N = 1e6 + 10, mod = 1e9;
// 计算幂2的n次幂  
int ksm(int i) {
	int q = 2, p = i;
	int res = 1;
	while (p) {
		if (p & 1) res *= 1ll * q;
		p >>= 1;
		q *= q * 1ll; 
	}
	return res;
}
int nums[20] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
long long f[1000000 + 10];
int main() {
	int n;
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < 20; i++) 
		for (int j = nums[i]; j <= n; j++) 
			f[j] += f[j - nums[i]], f[j] %= mod;
	cout << f[n];
//	int t;
//	int i;
//	for (i = 0;; i++) {
//		t = ksm(i);
//		if (t > N) break;
//		cout << t << ',';
//	}
//	cout << i;
	return 0;
}

