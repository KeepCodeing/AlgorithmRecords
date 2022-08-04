#include <iostream>
using namespace std;
// 把t的数据范围看成m的数据范围了... 
const int N = 1010;
int val[N], wei[N], f[N];
int main() {
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[t];
	return 0;	
}

