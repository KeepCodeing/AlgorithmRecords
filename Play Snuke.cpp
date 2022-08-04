#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1e9 + 10;
typedef long long LL;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	LL a, p, x, res = N;
	cin >> n;
	while (n--) {
		cin >> a >> p >> x;
		if (a >= x) continue;
		res = min(res, p);
	}
	if (res == N) res = -1;
	cout << res << endl;
	return 0;
}
