#include <iostream>
using namespace std;

// ��ϰ������ 
// �ԣ��ڶ�����������������
 
int main() {
	int n, m;
	int res = 1;
	long p;
	cin >> n >> m >> p;
	while(p) {
		if (p & 1) res = res * 1ll * n % m;
		p >>= 1;
		n = n * 1ll * n % m;
	}
	cout << res << endl;
	return 0;
}
