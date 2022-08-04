#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
map<int, int > m;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 2; i <= x / i; i++) {
			while (x % i == 0) {
				x /= i;
				m[i]++;
			}
		}
		if (x > 1) m[x]++;
	}
	LL res = 1;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
		int a = it->first, b = it->second;
		LL t = 1;
		while (b--) t = (t * a + 1) % mod;
		res *= t % mod;
	}
	cout << res;
	return 0;
}
