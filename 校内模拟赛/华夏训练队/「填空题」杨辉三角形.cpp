#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
long long f[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1 && j == 1) {
				f[i][j] = 1;
			} else {
				if (j - 1 < 1) f[i][j] = 1;
				else f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) cout << ' ';
		for (int j = 1; j <= i; j++) {
			cout << f[i][j];
			if (j != i) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
