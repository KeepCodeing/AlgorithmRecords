#include <iostream>
#include <cmath>
using namespace std;
// 谔谔，只能做下回溯题的样子

// 啊这...忘了去重..（结果不用去重...)

// 没搞清楚选择上限，看起来写回溯也不能完全无脑写，写的时候还是要记得什么是选择，什么是选择列表

class Solution {
	public:
		int primeCnt = 0;
		bool isPrime(int num) {
			int k = (int)sqrt((double)num);
			for (int i = 2; i <= k; i++) {
				if (num % i == 0) return false;
			}
			return true;
		}
		void dfs(int level, int deepth, int nums[], int sumNum, int used, int n) {
			if (used == deepth) {
				primeCnt += (int)isPrime(sumNum);
				return;
			}
			// 这里居然把deepth写成了选择上限，看起来变量名不能瞎起...
			for (int i = level; i < n; i++) {
				dfs(i + 1, deepth, nums, sumNum + nums[i], used + 1, n);
			}
		}
		int resolve() {
			int n, k;
			cin >> n >> k;
			int *nums = new int[n];
			for (int i = 0; i < n; i++) cin >> nums[i];
			dfs(0, k, nums, 0, 0, n);
			delete[] nums;
			return primeCnt;
		}
};

int main() {
	Solution s = Solution();
	cout << s.resolve();
	return 0;
}
