#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int nums[3];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> nums[0] >> nums[1] >> nums[2];
	sort(nums, nums + 3);
	cout << nums[0] << ' ' << nums[1] << ' ' << nums[2];
	return 0;
}
