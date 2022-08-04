#include <iostream>
#define endl '\n'
using namespace std;
const int N = 100;
int nums[N], f[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
		}
	}
	cout << f[n];
	return 0;
}
