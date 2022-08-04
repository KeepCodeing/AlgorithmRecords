#include <iostream>
#include <algorithm>
using namespace std;

// 屑题目，居然还是提高难度，不过其打算顺着做也只能先AC了 

int nums[4];
int main() {
	for (int i = 0; i < 4; i++) cin >> nums[i];
	sort(nums, nums + 4);
	for (int i = 0; i < 4; i++) {
		cout << nums[i];
		if (i != 3) cout << ' ';
	}
	return 0;
}
