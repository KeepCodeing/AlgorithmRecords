#include <iostream>
using namespace std;

const int N = 10;

int main() {
	int arr[N] = {2, 1, 4, 264, 13, 45, 5, 5, 2, 0};
	
	// ע����� <= N����Ϊ�˶Ա����һ��Ԫ�ص� 
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			// ��ô��������������������Ǹ���Ƥð������... 
			// ˼·�ܼ򵥣���������ǰһ���Ƿ���ڵ�ǰ�������ھ͵�����λ��.. 
			if (j > 0 && arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
		}
	}
	
	for (auto el: arr) {
		cout << el << ' ';
	}
	
	return 0;
}
