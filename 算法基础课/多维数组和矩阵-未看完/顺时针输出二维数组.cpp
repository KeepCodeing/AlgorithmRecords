#include <iostream>
using namespace std;
int main() {
	int LEN = 5;
	int arr[LEN][LEN];
	int temp = 1;
	// ��ʼ������ 
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			arr[i][j] = temp;
			temp++;
		}
	}
	// ��ӡ����(����д�ˣ����ܣ��� 
	
	return 0;
}
