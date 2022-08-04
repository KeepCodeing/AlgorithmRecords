#include <iostream>
using namespace std;
int n;
long long s[50010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int num;
	s[0] = 0;
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		s[i] = s[i - 1] + num; 
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i - 1; j++) {
			if (!((s[i] - s[j]) % 7)) {
				ans = max(ans, i - j);
				// 如果找到了就直接输出，虽然还是会超时 
				cout << ans;
				return 0 ;
			}
		}
	}
	cout << ans;
	return 0;
}
