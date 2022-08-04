#include <iostream>
#include <cstdio>
using namespace std;

// 考虑了下，m是元素个数，x是要凑的数（背包容积），x[i]是可以用的数，
// 因为要凑的数不能和可以用的数相同，所以这里要判断下 

// 说是简单，但是太池沼了调了半天...，以后碰到这种题应该先写个裸的模板，然后根据模板一点点的加需求 

// 坠毁ww，瑞了... 

const int M = 35, N = 1010;
int nums[M];
long long f[N];
int main() {
	int T;
	scanf("%d", &T);
	int m, res;
	while (T--) {
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) cin >> nums[i];
		res = 0;
		for (int k = 1; k <= m; k++) {
			// 对每个数都求次01背包方案数 
			fill(f, f + m + 1, 0);
			f[0] = 1;
			for (int i = 1; i <= m; i++) {
				for (int j = nums[k]; j >= nums[i]; j--) {
					// 一直卡在这里，没分清楚选的数和当前数的区别，nums[i]表示选的数，如1,2,3，nums[k]
					// 表示当前数，比如3，因为这个题选的数和要凑的数不能相同，所以这里要加个特判 
					if (nums[i] != nums[k]) f[j] += f[j - nums[i]];
				}
			}
			res += f[nums[k]];
		}
		cout << res << endl;
	}
	return 0;
}
