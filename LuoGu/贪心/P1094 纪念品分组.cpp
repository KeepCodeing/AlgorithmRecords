#include <iostream>
#include <algorithm>
using namespace std;

// 感觉贪心的策略是小的加大的 

int *arr;
int main() {
	int w, n;
	cin >> w >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	// for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	int left, right, cnt;
	// 之前把cnt设置为1是因为中间的数统计不到
	// 也想过双指针写成<=，但是考虑到中间的数
	// 不管是双倍大于等于或者小于w，都是只能
	// 被分成一组的，所以就把cnt设置为1了
	
	// 又看了遍发现cnt=1有问题，类似数据20 20 30 50 60 70
	// 全都可以分组,如果加个80，确实会落下一个数，但是这种
	// 情况并不是所有情况 
	left = 0, right = n - 1, cnt = 0;
	while (left <= right) {
		if (arr[left] + arr[right] <= w) {
			left++, right--, cnt++;
		} else {
			right--, cnt++;
		}
	}
	cout << cnt;
	delete[] arr;
	return 0;
}
