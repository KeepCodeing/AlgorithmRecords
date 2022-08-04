#include <iostream>
using namespace std;
const int N = 5010;
int val[N], wei[N], f[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[m];
	return 0;
}
