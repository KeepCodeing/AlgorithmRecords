#include <iostream>
using namespace std;

// exgcd�㷨��������������ax + by = m�ķ��̣����е��ҽ���m % gcd(a, b) == 0�÷��̲��н⣬Ҳ����˵m������a��b���Լ���ı�����
// �ر�ģ���m == 1ʱ��a��b�����������н�...�ܶ�ʱ������Ҫ�Ĳ�������û�н⣬����Ҫ��x��y��ֵ...���Ծ�����������Ҳ���������
// ����.. 

// ����.. 
int exgcd(int a, int b, int&x, int& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int r = exgcd(b, a % b, x, y);
	int temp = y;
	y = x - (a / b) * y;
	x = temp;
	return r;
}
int main() {
	
	return 0;
}
