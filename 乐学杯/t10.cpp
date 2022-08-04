#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1000 + 10;
int f[N], tm[N], val[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++) cin >> tm[i] >> val[i];
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= tm[i]; j--) {
			f[j] = max(f[j], f[j - tm[i]] + val[i]);
		}
	}
	cout << f[t];
	return 0;
}
