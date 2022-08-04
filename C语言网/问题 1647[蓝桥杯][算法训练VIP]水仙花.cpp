#include <iostream>
using namespace std;
int getPow(int x) {
	return x * x * x;
}
int main() {
	int n;
	cin >> n;
	if (getPow(n % 10) + getPow(n / 10 % 10) + getPow(n /100) == n) cout << "YES";
	else cout << "NO"; 
	return 0;
}
