#include <iostream>
#include <algorithm>
using namespace std;

// �о�̰�ĵĲ�����С�ļӴ�� 

int *arr;
int main() {
	int w, n;
	cin >> w >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	// for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	int left, right, cnt;
	// ֮ǰ��cnt����Ϊ1����Ϊ�м����ͳ�Ʋ���
	// Ҳ���˫ָ��д��<=�����ǿ��ǵ��м����
	// ������˫�����ڵ��ڻ���С��w������ֻ��
	// ���ֳ�һ��ģ����ԾͰ�cnt����Ϊ1��
	
	// �ֿ��˱鷢��cnt=1�����⣬��������20 20 30 50 60 70
	// ȫ�����Է���,����Ӹ�80��ȷʵ������һ��������������
	// ���������������� 
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
