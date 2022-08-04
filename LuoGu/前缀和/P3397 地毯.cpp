#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1e3 + 10;
int mp[N][N];
int s[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				mp[j][k] += 1;	
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << mp[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
