#include <iostream>
using namespace std;
// ��ŵ�����⣺��n-1�����ӿ���һ�����壬��n�����ӿ���һ�����壬
// һ���������β�������n-1�������Ƶ�B���ϣ��ٽ�n�����Ƶ�C����
// ���n-1�������Ƶ�C����

// �Ƶ���֪��һ��Ҫ�ƶ�2^n-1�� 
void hnt(char A, char B, char C, int n) {
	if (n <= 1) {
		cout << A << ' ' << B << ' ' << C << endl;
		return;
	}
	hnt(A, B, C, n - 1);
	hnt(A, C, B, 0);
	hnt(B, C, A, n - 1);
}
int main() {
	hnt('A', 'B', 'C', 3);
	return 0;
}
