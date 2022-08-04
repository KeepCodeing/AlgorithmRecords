#include <iostream>
using namespace std;
const int N = 1010;
int val[N], wei[N], f[N];

// 01背包不多谈，不过好久之前写过很多01背包问题，现在却忘得差不多了 

int main() {
	int n, v;
	cin >> n >> v;
	int vi, wi;
	// 这里用val表示代价（价钱），wei表示收获（权重） 
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[v];
	return 0;
} 
