#include <iostream>
using namespace std;
void ma(int arr[], int left, int mid, int right) {
	int *temp = new int[right - left + 1];
	int index = 0;
	int l_t = left;
	// 错误点一，这里要是等于mid的话就会产生left最右边元素和mid最左边元素重复的情况 
	// int m_t = mid;
	int m_t = mid + 1;
	while (l_t <= mid && m_t <= right) temp[index++] = arr[l_t] < arr[m_t] ? arr[l_t++] : arr[m_t++];
	
	while (l_t <= mid) temp[index++] = arr[l_t++];
	while (m_t <= right) temp[index++] = arr[m_t++];
	// 错误点二，这里无法保证i就是数组的起点，起点要从left元素算起，因为数组是被切分开来的 
	// for (int i = 0; i < index; i++) arr[i] = temp[i];
	for (int i = 0; i < index; i++) arr[left + i] = temp[i];
	delete[] temp;
}
void s(int arr[], int left, int right) {
	if (left >= right) return;
	int mid = left + ((right - left) >> 1);
	s(arr, left, mid);
	s(arr, mid + 1, right);
	ma(arr, left, mid, right);
}
void ms(int arr[], int len) {
	s(arr, 0, len - 1);
}
int main() {
	int len;
	cin >> len;
	int arr[len];
	for (int i = 0; i < len; i++) cin >> arr[i];
	ms(arr, len);
	for (int i = 0; i < len; i++) cout << arr[i] << ' ';
	return 0;
}
