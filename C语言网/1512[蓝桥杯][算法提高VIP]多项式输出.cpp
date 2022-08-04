#include <iostream>
using namespace std;

// 好久以前还是萌豚的时候就做个这个题了，那时候觉得还很坑的...
// 虽说现在也没好到哪里去，但是应该写起来会轻松点吧

// 坠毁三次（无能），还没做出来 
 
int *nums;
int main() {
	int n;
	cin >> n;
	nums = new int[n + 5];
	for (int i = 1; i <= n + 1; i++) {
		cin >> nums[i];
	}
	// 当时本坑的就是减号，现在看来与其放前面输出不如放后面，这样
	// 只用判断当前是否是第一个数即可 
	// 被坑了...，题目给的n，但是要输入n+1个数..，前面改了，这里没改（不是这样哦，没看题目样例又坠毁了） 
	int xs = n;
	for (int i = 1; i <= n + 1; i++) {
		if (nums[i] > 0) {
			if (i != 1) cout << '+';
			// 大于1才有系数 
			if (nums[i] > 1) cout << nums[i];
		} else if (nums[i] < 0) {
			if (nums[i] == -1) cout << '-';
			else cout << nums[i];
		}
		// 不等于0才有未知量 
		if (nums[i] != 0 && xs != 0) cout << "x";
		if (xs > 1) cout << "^" << xs;
		xs--;
	}
	delete[] nums;
	return 0;
}
