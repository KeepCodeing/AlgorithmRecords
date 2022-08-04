#include <iostream>
#define endl '\n'
using namespace std;
const int N = 10;
int f[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0 && j == 0) f[i][j] = 1;
			else if (i == 0) f[i][j] = 1;
			else if (j == 0) f[i][j] = 1;
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[2][2];
	return 0;
} 
