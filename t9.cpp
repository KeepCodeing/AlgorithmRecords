#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 100000 + 10;
int nums[N];

bool cmp(const int a, const int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, p, q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) nums[i] = i;
	while (m--) {
		cin >> p >> q;
		if (p) sort(nums + q, nums + n + 1);
		else sort(nums + 1, nums + q + 1, cmp);
	}
	for (int i = 1; i <= n; i++) {
		cout << nums[i];
		if (i != n) cout << ' ';
	}
	return 0;
}
