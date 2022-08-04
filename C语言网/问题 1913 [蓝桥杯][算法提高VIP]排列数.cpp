#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int nums[10];
	for (int i = 0; i <= 9; i++) nums[i] = i;
	do {
		n--;
		if (!n) {
			for (int i = 0; i <= 9; i++) cout << nums[i];
			break;
		}
	} while(next_permutation(nums, nums + 10));
	return 0;
}
