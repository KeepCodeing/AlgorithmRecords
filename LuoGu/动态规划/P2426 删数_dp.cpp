#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
const int N = 100 + 10;
int nums[N], f[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j++) {
			if (i == j) f[i][j] = nums[i];
			else {
				// 从右往左删，xi是n - j个数，xk是剩下的数的数量j - i 
				f[i][j] = abs(nums[i] - nums[j]) * (j - i + 1);
				
			}
		}
	}
	return 0;
}
