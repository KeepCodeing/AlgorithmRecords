#include <iostream>
#include <algorithm>
using namespace std;
// ����һ�����飬Ҫ�����������Ԫ��ƴ����һ������ɵ���С��
// ˼·������sort�ĶԱȹ����Ԫ�ؽ��в��� 
bool s(int a, int b) {
	string t1, t2;
	// �����ַ���������ƴ����һ��
	t1 += a, t2 += b;
	// �Աȴ�С 
	// a.compare(b)  a�ַ����е��ַ�ASCII�����b�ַ����е��ַ��ͻ᷵��1�����򷵻�-1����ͬ����0 
	return t1.compare(t2);
}
int main() {
	int arr[] = {3, 32, 321};
	sort(arr, arr + 3, s);
	for (int i = 0; i < 3; i++) {
		cout << arr[i];
	}
	return 0;
}
