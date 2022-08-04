#include <iostream>
#define endl '\n'
using namespace std;
const int N = 10000 + 10;
bool ax[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int L, M, l, r, res = 0;
	cin >> L >> M;
	while (M--) {
		cin >> l >> r;
		for (int i = l; i <= r; i++) ax[i] = true;
	}
	for (int i = 0; i <= L; i++) res += !ax[i];
	cout << res;
	return 0;
}
