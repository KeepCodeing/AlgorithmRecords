#include <iostream>
using namespace std;
int main() {
	int b, p, k, s = 1;
	int b1, p1;
	cin >> b >> p >> k;
	b1 = b, p1 = p;
	while(p1) {
		// ע��*1ll��˳�򣬲��Ծͻ�������´𰸴��� 
		if (p1 & 1) s = s * 1ll * b1 % k;
		b1 = b1 * 1ll * b1 % k;
		p1 >>= 1;
	}
	// ���е�p����0�����������Ϊ���û���������.. 
	cout << b << "^" << p << " mod " << k << '=' << s % k; 
	return 0;
}
