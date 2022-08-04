#include <iostream>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= wei[i]; j--) {
			f[j] = max(f[j], f[j - wei[i]] + val[i]);
		}
	} 
	
	for (int i = 1; i <= n; i++) {
		for (int j = wei[i]; j <= m; j++) {
			f[j] = max(f[j], f[j - wei[i]] + val[i]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= wei[i]; j--) {
			for (int k = t; k >= tm[i]; k--) {
				f[j][k] = max(f[j][k], f[j - wei[i]][k - tm[i]] + val[i]);
			}
		} 
	}
	
	for (int i = 1; i <= s; i <<= 1) {
		
		s -= i;
	}
	return 0;
}
