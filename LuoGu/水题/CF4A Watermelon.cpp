#include <iostream>
using namespace std;

// 偶数=偶数+偶数，但是2是例外 

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0 && n != 2) cout << "YES"; 
	else cout << "NO";
	return 0;
}
