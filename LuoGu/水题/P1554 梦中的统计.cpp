#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int arr[10] = {0};
	for (int i = m; i <= n; i++) {
		int temp = i;
		while (temp) {
			// ����Ƚ����������ͳ�������ַ��������������ַ���
			// �����Ǹ���ַ���ʲô�� 
			arr[temp % 10]++;
			temp /= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
		if (i != 9) cout << ' ';
	}
	return 0;
}
