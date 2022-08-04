#include <iostream>
#include <algorithm>
using namespace std;

// 坠毁，这个题正解BFS... 

string nums;
int n;
int main() {
	cin >> n;
	cin >> nums;
	string tt = nums;
	int minStep = 0x3fffffff;
	if (nums.find("2012") != nums.npos) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j < n; j++) {
			swap(nums[i], nums[j]);
			cnt++;
			if (nums.find("2012") != nums.npos) {
				minStep = min(minStep, cnt);
				break;
			}
			swap(nums[i], nums[j]);
		}
		//nums = tt;
	}
	if(minStep == 0x3fffffff) cout << -1;
	else cout << minStep;
	return 0;
}
