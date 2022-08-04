#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 100 + 10;

int mp[N][N], f[N][N];
int r, c;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mp[i][j];
		}
	}
	memset(f, -0x3f, sizeof f);
	f[1][1] = mp[1][1];
	// 先循环列，再循环行，这样才能保证无后效性。
	for (int j = 2; j <= c; j++) {
		for (int i = 1; i <= r; i++) {
			f[i][j] = max(f[i + 1][j - 1], max(f[i][j - 1], f[i - 1][j - 1])) + mp[i][j];
		}
	}
	cout << f[r][c] << endl;
	return 0;
}
/*
7 12
21 12 1 25 10 10 10 17 1 23 23 1
1 11 24 12 17 25 5 15 16 16 22 9
17 15 10 24 23 8 18 8 10 6 9 9
2 23 8 13 14 22 21 22 11 22 3 22
18 22 22 5 18 1 11 23 23 16 5 15
24 10 21 11 2 2 15 19 7 1 4 9
7 20 8 22 23 8 23 24 20 3 2 1

*/
