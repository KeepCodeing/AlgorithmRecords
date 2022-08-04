#include <iostream>
using namespace std;

// 此为优化后的01背包 

const int N = 1010;
int val[N], wei[N];
int f[N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[v];
	return 0;
} 
