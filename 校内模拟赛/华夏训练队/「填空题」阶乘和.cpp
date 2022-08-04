#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long sum = 0, f = 1;
	for (int i = 1; i <= 10; i++) {
		f *= i;
		sum += f;
	}
	cout << sum;
	return 0;
}
