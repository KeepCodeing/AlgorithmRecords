#include <iostream>
#include <map>
using namespace std;
const int N = 100010;
map<int, int > mp;
int main() {
	int n, m, t;
	cin >> n >> m >> t;
	while (m--) {
		int ts, id;
		cin >> ts >> id;
		mp[id] += 2;
		for (int i = 1; i <= n; i++) {
			if (mp[i] != 0 && i != id) mp[i]--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (mp[i] > 3) ans++;
	}
	cout << ans;
	return 0;
}
