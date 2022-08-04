#include <iostream>
#include <algorithm>
using namespace std;
int nums[110];
bool isAlpha(int x) {
	return x >= 'A' && x <= 'Z';
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> nums[i];
	// 先排序还是先输出，这是个问题 
	sort(nums, nums + n);
	for (int i = 0; i < n; i++) {
		if ((nums[i] % q)) {
			if (isAlpha(nums[i])) cout << (char)nums[i] << ' ';
			else cout << nums[i] << ' ';
		}
	}
	return 0;
}
