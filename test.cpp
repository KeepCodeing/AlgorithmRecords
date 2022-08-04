#include <iostream>
using namespace std;

typedef long long LL;

LL res = 0;
LL cal(int n) {
	if (n == 1) return res = 1;
	LL temp = n * cal(n - 1);
	cout << temp << endl;
	return res += n * cal(n - 1);
}

int main() {
//	for (int i = 1; i <= 10; i++) cout << cal(i) << endl;
	cal(10);
	cout << res << endl;
	return 0;
}
