#include <iostream>
#include <algorithm>
using namespace std;

// ˫ָ������� 
// ˫ָ���Ȼ�����и�����ָ����ż�Ե����⣬���nΪż����
// �������Ϊ�����һ�����е�������������һ�����
// nΪ�����������ֻ���������һ������һ��ʼ�������
// �������Ǹĳ�ż�������ָ�û��...������������˫ָ��
// �������������Ҫ�����ж���ż�ԣ�����ת�������
// �����жϣ���Ϊ���鳤��Ϊ���м�Ԫ�ز��ö���Ϊż
// �������м�Ԫ��... 

// ��Ŀ�������ݷ�Χ 
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
