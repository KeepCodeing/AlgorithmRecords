#include <iostream>
#include <bitset> 
using namespace std;
int main() {
	int n;
	cin >> n;
	// bitset������w.. 
	bitset<8> b(n);
	cout << b;
	return 0;
}
