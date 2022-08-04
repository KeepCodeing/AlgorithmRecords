#include <iostream>
using namespace std;

// 卡特兰数的板子... 

const int N = 20;
typedef long long LL;
LL f[N];
int main() {
	int n;
	cin >> n;
	f[0] = 1;
	// 递推式，当前卡特兰数=上一个卡特兰数*(四倍的当前位置 - 2) / 当前位置 + 1 
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * (i * 4 - 2) / (i + 1);
	cout << f[n];
	return 0;
}
