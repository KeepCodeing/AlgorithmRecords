#include <iostream>
using namespace std;

void mergeArr(int arr[], int left, int mid, int right) {
	int *temp = new int[right - left + 1];
	int index = 0;
	int left_t = left;
	int mid_t = mid + 1;
	// �Ա��������������Ԫ�صĴ�С��С�ķ�ǰ�� 
	while (left_t <= mid && mid_t <= right) {
		temp[index++] = arr[left_t] < arr[mid_t] ? arr[left_t++] : arr[mid_t++];
	}
	// ��Ϊ���治һ���ܰ����������Ԫ�ض��Ա��꣬�������ﻹ��Ҫ��
	// �����ǲ����������Ϊ���������Ԫ�ض���������ˣ�����û�Ա�
	// ���һ������Ҳ�͸����� 
	while (left_t <= mid) temp[index++] = arr[left_t++];
	while (mid_t <= right) temp[index++] = arr[mid_t++];
	
	for (int i = 0; i < index; i++) arr[left + i] = temp[i];
	
	delete[] temp;
}

void mSort(int arr[], int left, int right) {
	if (left >= right) return;
	// ����λ���㽫right-left��Сһλ 
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

