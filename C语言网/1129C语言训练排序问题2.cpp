#include <iostream>
#include <algorithm>
using namespace std;

// copy...

int nums[10];
int main() {
	for (int i = 0; i < 10; i++) cin >> nums[i];
	sort(nums, nums + 10);
	for (int i = 9; i >= 0; i--) {
		cout << nums[i];
		if (i != 0) cout << ' ';
	}
	return 0;
}
