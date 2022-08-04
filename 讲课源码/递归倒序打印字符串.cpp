#include <iostream>
using namespace std;

typedef long long LL;
LL fib(int n) {
	if (n <= 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	cout << fib(9);
	return 0;
}
