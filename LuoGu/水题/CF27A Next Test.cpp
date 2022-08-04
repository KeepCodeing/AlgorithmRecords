#include <iostream>
#include <algorithm>
using namespace std;

// 水题第十三弹...除了水题就没别的题可刷了... 

const int N = 3000 + 10;
int nums[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	if (n == 1) {
		cout << nums[0] + 1;
		return 0;
	}
	sort(nums, nums + n);
	for (int i = 0; i < n - 1; i++) {
		if (nums[i + 1] != nums[i] + 1) {
			cout << nums[i] + 1;
			return 0;
		}
	}
	return 0;
}
