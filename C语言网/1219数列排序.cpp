#include <iostream>
#include <vector>
using namespace std;

// 规律是小的数从后开始扫，大的数从前开始扫，这样才符合输出顺序 

int nums[9];
// 为了控制输出格式搞了个矢量 
vector<int > vec;
int main() {
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 9; i++) cin >> nums[i];
		for (int i = 8; i >= 0; i--) {
			if (nums[i] + 1 <= nums[0]) vec.push_back(nums[i]); 
		}
		// 以nums[0]作为分界点 
		vec.push_back(nums[0]); 
		for (int i = 0; i <= 8; i++) {
			if (nums[i] - 1 >= nums[0]) vec.push_back(nums[i]); 
		}
		int vLen = vec.size();
		for (int i= 0; i < vLen; i++) {
			cout << vec[i];
			if (i != vLen - 1) cout << ' ';
		}
		cout << endl;
		vec.clear();
	}
	return 0;
}
