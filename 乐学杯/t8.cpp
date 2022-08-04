#include <iostream>
#define endl '\n'
using namespace std;
const int N = 40;
long long res[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	res[1] = 1;
	 res[2] = 2;
	for (int i = 3; i <= n; i++) res[i] = res[i - 1] + res[i - 2];
	cout << res[n];
	return 0;
}
