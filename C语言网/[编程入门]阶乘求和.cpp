#include <iostream>
using namespace std;
typedef unsigned long long ULL; 
int main() {
	ULL temp = 1, res = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) temp *= i, res += temp;
	cout << res;
	return 0;
}
