#include <iostream>
using namespace std;
int main() {
	/*大概思路就是跳1级一种，两级也是1种，3级就是两种，而跳4级就是1级1种加两级1种加3级+1级一种，*/ 
	int f[100];
	f[0] = f[1] = f[2] = 1;
	f[3] = 2;
	for (int i = 4; i <= 30; i++) {
		f[i] = f[i - 1] + f[i - 3];
	}
	cout << f[30] << endl;
	return 0;
}
