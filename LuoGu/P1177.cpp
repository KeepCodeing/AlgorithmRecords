#include <iostream>
using namespace std;
// 2 7 4 3
void quick_sort(long arr[], int left, int right) {
	// 退出递归的条件，必不可少 
	if (left > right) return;
	long index_left = left, index_right = right, temp;
	long num = arr[left];
	while (index_left != index_right) {
		// 找到右边比基准值小的数 
		while (arr[index_right] >= num && index_left < index_right) 
			index_right--;
		// 找到左边比基准值大的数 
		while (arr[index_left] <= num && index_left < index_right)
			index_left++;
		// 交换左右两边的值，交换完了就能保证左区间的值全都小于
		// 基准值，右区间的值全都大于基准值 
		temp = arr[index_left];
		arr[index_left] = arr[index_right];
		arr[index_right] = temp;
	}
	// 最后将基准值还原到它位置上 
	temp = arr[index_left];
	arr[index_left] = arr[left];
	arr[left] = temp;
	quick_sort(arr, left, right - 1);
	quick_sort(arr, left + 1, right);
	
}
int main() {
	int n;
	cin >> n;
	long *arr = new long[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
} 
