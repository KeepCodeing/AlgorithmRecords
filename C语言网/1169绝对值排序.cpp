#include <iostream>
#include <algorithm>
using namespace std;

// 变了一点，继续copy，主要是提供一个排序函数，如果自己在输入的过程
// 中就搞得是绝对值，那么在输出的时候还要还原，而还原又得知道下标，所以
// 非常麻烦
 
bool cmp(int a, int b) {
	return abs(a) > abs(b);
}
int nums[110];

int main() {
	int n;
	while (cin >> n) {
		if (!n) break;
		for (int i = 0; i < n; i++) cin >> nums[i];
		sort(nums, nums + n, cmp);
		for (int i = 0; i < n; i++) {
			cout << nums[i];
			if (i != n - 1) cout << ' ';
		}	
		cout << endl;
	}
	return 0;
}
