#include <iostream>
#include <algorithm>
using namespace std;
int nums[100];
int main() {
	int n;
	cin >> n;
	int c = 1;
	for (int i = 0; i < n; i++) c *= 2;
	// c -= 1;
	for (int i = 1; i <= c; i++) nums[i] = i;
	int cnt = 0;
	do {
		cnt++;
		for (int i = 1; i <= c; i++) {
			cout << nums[i] << ' ';
		}
		cout << endl;
		if (nums[1] = 1 && nums[2] == 3 && nums[3] == 2 && nums[4] == 4 && nums[5] == 5
		&& nums[6] == 7 && nums[7] == 6 && nums[8] == 8) {
			cout << cnt << endl;
			break;
		}
		
	} while (next_permutation(nums + 1, nums + c + 1));
	return 0;
}
