#include <iostream>
using namespace std;

void mergeArr(int arr[], int left, int mid, int right) {
	int *temp = new int[right - left + 1];
	int index = 0;
	int left_t = left;
	int mid_t = mid + 1;
	// 对比左右两个区域的元素的大小，小的放前面 
	while (left_t <= mid && mid_t <= right) {
		temp[index++] = arr[left_t] < arr[mid_t] ? arr[left_t++] : arr[mid_t++];
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
	int arr[10];
	for (int i = 9; i >= 0; i--) arr[i] = i;
	mergeSort(arr, 10);
	for (int i = 0; i <= 9; i++) cout << arr[i] << ' ';
	return 0;
}

