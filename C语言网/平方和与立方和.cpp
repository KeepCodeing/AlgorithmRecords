#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int l, r, ra, rb;
	while (cin >> l >> r) {
		ra = rb = 0;
		for (int i = l; i <= r; i++) {
			if (i % 2) rb += i * i * i;
			else ra += i * i;
		}
		cout << ra << ' ' << rb << endl;
	}
	return 0;
}
