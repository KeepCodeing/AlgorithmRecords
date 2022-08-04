#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100 + 10;
int nums[N];
int main() {
	int n, ans = 0;
	bool flag;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	while (true) {
		flag = false;
		for (int i = 1; i <= n; i ++) {
			if (nums[i] % 2) nums[i] += 1, ans += 1;
			if (i == 1) {
				nums[i] /= 2;
				nums[n] += nums[i];
			} else {
				nums[i] /= 2;
				nums[i - 1] += nums[i]; 
			}
		}
		// 1 2 6.
		// 2 1 6
		// 2 4 3
		// 1 4 4
		// 3 2 4
		// 3 4 2
		// 
		for (int i = 1; i <= n - 1; i++) {
			if (nums[i] != nums[i + 1]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) break;
	}
	printf("%d", ans);
	return 0;
}
