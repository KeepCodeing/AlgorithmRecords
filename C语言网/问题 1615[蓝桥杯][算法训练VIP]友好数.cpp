#include <iostream>
using namespace std;

int ys(int x) {
	int res = 0;
	for (int i = 1; i <= x / i; i++) {
		if (!(x % i)) {
			res += i;
			// ��ĿҪ��Լ�������Լ�������Ҫ���Ե����������Ҳ����i=1ʱ�� 
			if (i != x / i && x != x / i) res += x / i;
		}
	}
	return res;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a == ys(b) && ys(a) == b) cout << "yes";
	else cout << "no"; 
	return 0;
}
