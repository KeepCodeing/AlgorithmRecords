#include <iostream>
#include <algorithm>
using namespace std;

// 第一眼以为是01背包ww，然后发现有n个数，但是只能选k个，这就和01背包不一样了，01背包是从n个数里选若干个w
// 看了题解才知道是个排序，因为买电视可以倒着赚钱，所以价格越小赚的越多...

// 所以说如果题目是从n个数里选若干个数，然后求最优解，那可能是Dp（特指背包），如果是选k个数，那就绝对不是Dp 

const int N = 110;
int nums[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// 注意排序范围 
	sort(nums + 1, nums + n + 1);
	int res = 0;
	for (int i = 1; i <= m; i++) {
		// 只选可以赚钱或者不亏钱的电视 
		if (nums[i] <= 0) res += -nums[i];
	}
	cout << res;
	return 0;
}
