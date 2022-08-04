#include <iostream>
#include <map>
using namespace std;
map<int, int > m;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 2; i <= x / i; i++) {
			while (x % i == 0) {
				m[i]++;
				x /= i;
			}
		}
		if (x > 1) m[x]++;
	}
	int res = 1;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
		res *= it->second + 1;
	}
	cout << res;
	return 0;
}
