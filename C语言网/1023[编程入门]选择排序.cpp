#include <iostream>
#include <algorithm>
using namespace std;

// 有什么自己写选排的必要吗，STL IS GOD 

int nums[10];
int main() {
	for (int i = 0; i < 10; i++) cin >> nums[i];
	sort(nums, nums + 10);
	for (int i = 0; i < 10; i++) {
		cout << nums[i];
		if (i != 9) cout << endl;
	}
	return 0;
}
