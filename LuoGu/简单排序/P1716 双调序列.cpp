#include <iostream>
#include <algorithm>
using namespace std;

// 双指针加排序 
// 双指针居然还会有个左右指针奇偶性的问题，如果n为偶数，
// 程序会因为少输出一个换行导致两个数连在一起，如果
// n为奇数，程序又会少输出最后一个数（一开始补了这个
// 数，但是改成偶数的了又改没了...），看起来用双指针
// 做这种输出工作要额外判断奇偶性，而翻转数组可以
// 不用判断，因为数组长度为奇中间元素不用动，为偶
// 不存在中间元素... 

// 题目给的数据范围 
long *arr;
int main() {
	int n;
	cin >> n;
	arr = new long[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int left = 0, right = n - 1;
	while (left < right) {
			cout << arr[right--] << endl << arr[left++] << endl;
		}
	if (n % 2 == 0) {
		while (left < right) {
			cout << arr[right--] << endl << arr[left++] << endl;
		}
	} else {
		while (left < right) {
			cout << arr[right--] << endl << arr[left++];
			if (left != right - 1) cout << endl;
		}
		cout << arr[left];
	}
	delete[] arr;
	return 0;
}
