#include <iostream>
#define endl '\n'
using namespace std;

typedef long long LL;
LL qp(int n, int q) {
	LL res = 1;
	while (q) {
		if (q & 1) res = res * n;
		q >>= 1;
		n *= n;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout << qp(2, 10);
	return 0;
}
