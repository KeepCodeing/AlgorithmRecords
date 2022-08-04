#include <iostream>
using namespace std;
const int N = 100010;
int s[N], t[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ans = -1;
	for (int i = 0, j = 0; i < n; i++) {
		// 用一个桶计数，统计当前元素出现的次数，如果某个元素 
		// 重复出现了，剔除之前的元素，并且让j向前指到i的位置
		// 这样最长序列的值就又恢复到1了 
		t[s[i]]++;
		while (t[s[i]] > 1) {
			t[s[j]]--;
			j++;
		}
		// 注意这里是每一步都更新答案，而不是出现重复后才更新 
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}

// 坠毁，思路过于简单 
//#include <iostream>
//using namespace std;
//
//// 双指针来做，应该就是第一个指针指向第一个不重复元素，
//// 第二个指针依次向后指，如果发现了重复元素，统计长度
//// 并且将第一个指针指向第二个指针，第二个指针继续向后指 
//
//// 双指针的作用：优化O(n^2)的朴素算法
//// 双指针的用场：一般是对比，交换等。 
//
//int nums[100010];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> nums[i];
//	// 双指针模板（不一定就要i不动或者j不动）
//	// 指向开头 
//	int j = 0; 
//	int ans = -1;
//	// 每次对比后一个元素是否和当前元素相同 
//	int pre = nums[0];
//	for (int i = 1; i < n; i++) {
//		// 思路：i往后指，j为起点，如果i重复了，更新答案，把
//		// j指向i（也就是第一个重复数字的位置） 
//		if (nums[i] == pre) ans = max(ans, i - j + 1), j = i;
//		pre = nums[i];
//	} 
//	cout << ans;
//	return 0;
//}
