#include <iostream>
using namespace std;
int main() {
	int n = 1200000;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!(n % i)) cout << i << endl, cnt++; 
	}
	cout << cnt;
	return 0;
}
