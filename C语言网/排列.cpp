#include <iostream>
#include <algorithm>
using namespace std;
const int N = 4;
int nums[N];
int main() {
	int T, cnt;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 4; i++) cin >> nums[i];
		cnt = 1;
		do {
			for (int i = 0; i < 4; i++) cout << nums[i];
			if (!(cnt++ % 6)) cout << endl;
			else cout << ' ';
		} while(next_permutation(nums, nums + 4));
		cout << endl;
	}
	return 0;
}
