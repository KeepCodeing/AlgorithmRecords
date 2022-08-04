#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL res = 0;
int main() {
	int n;
	ULL temp = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) temp *= i, res += temp;
	cout << res;
	return 0;
}
