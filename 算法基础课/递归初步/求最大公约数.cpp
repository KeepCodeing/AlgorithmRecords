#include <iostream>
using namespace std;
// շת�������m % n == 0��˵��n�������Լ����m % n == k,˵����û�еõ����Լ��
// ������n % k��ֱ�����õ�0Ϊֹ 
int gcd(int m, int n) {
	return m % n ? gcd(n, m % n) : n;
}
// ��չ����С��������Ϊm*n/���Լ��
int lcm(int m, int n, int d) {
	return m * n / d;
} 
int main() {
	cout << gcd(60, 25) << endl;
	cout << lcm(60, 25, gcd(60, 25));
	return 0;
}
