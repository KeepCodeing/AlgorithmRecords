#include <iostream>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	int f[100][100];
	int aLen = a.size(), bLen = b.size();
	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[aLen][bLen];
	return 0;
}
