#include <iostream>
using namespace std;
// 给出一个数组，如{2, 5, 1, 3, 4}，要求统计出满足逆序对的元素的个数
// 逆序对：左边元素大于右边元素，2 1， 5 1， 5 3，5 4，等

// 利用归并排序的思想，在合并的过程中判断元素大小 
int count = 0;

void mergeArr(int arr[], int left, int mid, int right) {
	int *temp = new int[right - left + 1];
	int index = 0;
	int left_t = left;
	int mid_t = mid + 1;
	// 对比左右两个区域的元素的大小，小的放前面 
	while (left_t <= mid && mid_t <= right) {
		if (arr[left_t] <= arr[mid_t]) {
			temp[index++] = arr[left_t++];
		} else {
			temp[index++] = arr[mid_t++];
			// 改写部分，因为归排后位于该元素右边的一定是小于该元素的，所以
			// 这部分元素都满足逆序对要求 
			count += mid - left_t + 1;
		}
	}
	// 因为上面不一定能把两个区域的元素都对比完，所以这里还需要在
	// 将它们补充进来，因为两个区域的元素都是有序的了，所以没对比
	// 完的一定更大，也就更靠后 
	while (left_t <= mid) temp[index++] = arr[left_t++];
	while (mid_t <= right) temp[index++] = arr[mid_t++];
	
	for (int i = 0; i < index; i++) arr[left + i] = temp[i];
	
	delete[] temp;
}

void mSort(int arr[], int left, int right) {
	if (left >= right) return;
	// 利用位运算将right-left缩小一位 
	int mid = left + ((right - left) >> 1);
	mSort(arr, left, mid);
	mSort(arr, mid + 1, right);
	mergeArr(arr, left, mid, right);
}

void mergeSort(int arr[], int len) {
	mSort(arr, 0, len - 1);
}

int main() {
	int arr[5] = {2, 5, 1, 3, 4};

	mergeSort(arr, 5);
	cout << count << endl;
	return 0;
}

