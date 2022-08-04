#include <iostream>
using namespace std;
// 2 7 4 3
void quick_sort(long arr[], int left, int right) {
	// �˳��ݹ���������ز����� 
	if (left > right) return;
	long index_left = left, index_right = right, temp;
	long num = arr[left];
	while (index_left != index_right) {
		// �ҵ��ұ߱Ȼ�׼ֵС���� 
		while (arr[index_right] >= num && index_left < index_right) 
			index_right--;
		// �ҵ���߱Ȼ�׼ֵ����� 
		while (arr[index_left] <= num && index_left < index_right)
			index_left++;
		// �����������ߵ�ֵ���������˾��ܱ�֤�������ֵȫ��С��
		// ��׼ֵ���������ֵȫ�����ڻ�׼ֵ 
		temp = arr[index_left];
		arr[index_left] = arr[index_right];
		arr[index_right] = temp;
	}
	// ��󽫻�׼ֵ��ԭ����λ���� 
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
