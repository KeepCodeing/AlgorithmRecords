#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ˮ�������70AC��... 

int main() {
	int arr[3];
	char c[3];
	for (int i = 0; i < 3; i++) cin >> arr[i];
	for (int i = 0; i < 3; i++) cin >> c[i];
	sort(arr, arr + 3);
	// ��Ҫ����Ŀ�����˹�ϵʽ��A<B<C�������ABCת��Ϊ�±꣬��֪
	// ��СΪA�����ΪC�� �����������ABCת��Ϊ�±꣬���ɵõ��� 
	// ���ַ������� 
	cout << arr[abs('A' - c[0])] << ' ' << arr[abs('A' - c[1])] << ' ' << arr[abs('A' - c[2])];
	return 0;
}
