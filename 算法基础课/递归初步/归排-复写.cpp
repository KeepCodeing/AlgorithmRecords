#include <iostream>
using namespace std;
void ma(int arr[], int left, int mid, int right) {
	int *temp = new int[right - left + 1];
	int index = 0;
	int l_t = left;
	// �����һ������Ҫ�ǵ���mid�Ļ��ͻ����left���ұ�Ԫ�غ�mid�����Ԫ���ظ������ 
	// int m_t = mid;
	int m_t = mid + 1;
	while (l_t <= mid && m_t <= right) temp[index++] = arr[l_t] < arr[m_t] ? arr[l_t++] : arr[m_t++];
	
	while (l_t <= mid) temp[index++] = arr[l_t++];
	while (m_t <= right) temp[index++] = arr[m_t++];
	// �������������޷���֤i�����������㣬���Ҫ��leftԪ��������Ϊ�����Ǳ��зֿ����� 
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
