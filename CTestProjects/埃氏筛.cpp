#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr;
	// �ȱ��Ϊfalse����ʾ������ 
	arr = new int[n]();
	// �����ӣ�0��1��������
	arr[0] = arr[1] = true; 
	for (int i = 2; i <= n; i++) {
		// ��������������䱶��ɸ�� 
		if (!arr[i]) {
			// ע�����j=i*2��j+=1���Ǳ�ʾɸ���� 
			for (int j = i * 2; j <= n; j += i) {
				// ɸ�������ı��� 
				arr[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!arr[i]) cout << i << endl;
	}
	delete[] arr; 
	return 0;
}
