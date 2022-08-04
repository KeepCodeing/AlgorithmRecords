#include <iostream>
using namespace std;

// 完全背包求方案数，但是这里还要高精度 

const int N = 1010, M = 110;
int f[N];
int main() {
	int n, k;
	cin >> n >> k;
	f[0] = 1;
	// 板子都记错了..
	// 物品个数是有多少种钱，背包容积是要花多少钱 
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			f[j] += f[j - i];
		}
	}
	cout << f[n];
	return 0;
}
