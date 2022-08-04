#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

// 数据范围太大，单纯的暴力肯定会超时，不过这个题可以
// 贪心解，找到数组中比当前元素大的最少的值或者等于的值即可
// 不过要注意如果要找的值就是最大值应该用这个值减稍小的值

// 主要用的是lower_bound(first, last, ele)函数，它可以返回比当前元素大的第一个
// 值的位置，如果当前值就是最大值，它会返回last，而last实际是越界的
// 对比的话对比是当前元素减其前一个元素小还是其后一个元素减其小即可 

// 看题解发现没有那么多特判，只用判断最小值和最大值即可 

vector<int > arr;
int main() {
	int m, n, temp;
	cin >> m >> n;
	int res = 0;
	for (int i = 0; i < m; i++) cin >> temp, arr.push_back(temp);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cin >> temp;
		// 转换成下标，并且这样不会越界 
		int index = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();
		if (temp == arr[index]) {
			res += 0;
		} else if (index == 0 && m >= 2) {
			// 如果这个值是最小值
			 res += arr[index] - temp; 
		} else if (index == m - 1 && m >= 2 && temp >= arr[index]) {
			// 如果这个值是最大值，减比其小的值即可 
			res += temp - arr[index];
		} else if (m == 1) {
			res += temp > arr[0] ? temp - arr[0] : arr[0] - temp;
		} else {
			int left;
			// 其它值 
			left = index - 1;
			// 比当前数大的值-当前数小还是当前值-比当前值小的值小，注意这里可能出现小值减大值的情况，
			// 不过其没想懂，index是第一个大于等于temp的下标，left应该就是刚刚小于temp的下标 
			res += min(abs(arr[index] - temp), abs(temp - arr[left]));
		}
	}
	cout << res;
	return 0;
}
