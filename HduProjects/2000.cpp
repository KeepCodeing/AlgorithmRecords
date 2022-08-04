#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	char cs[3];
	while (1) {
		if (!(cin >> cs[0] >> cs[1] >> cs[2])) break;
		sort(cs, cs + 3);
		cout << cs[0] << ' ' << cs[1] << ' ' << cs[2] << endl;
	}
	return 0;
} 
