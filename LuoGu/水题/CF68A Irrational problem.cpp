#include <iostream>
using namespace std;

// ˮ���ʮ����.. 

int main() {
	int p1, p2, p3, p4, a, b, ans = 0;
	cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
	for (int i = a; i <= b; i++) if (i % p1 == i && i % p2 == i && i % p3 == i && i % p4 == i) ans++;
	cout << ans;
	return 0;
}
