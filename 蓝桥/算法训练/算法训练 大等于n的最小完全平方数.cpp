#include <iostream>
using namespace std;
int main() {
	int n;
	
	cin >> n;
	int s = n / 2;
	while (s * s < n) {
		s++;
	}
	cout << s * s;
	return 0;
}
