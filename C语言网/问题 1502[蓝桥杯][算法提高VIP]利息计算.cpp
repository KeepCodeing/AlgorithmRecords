#include <iostream>
#include <cstdio>
using namespace std;
typedef double dl;
int main() {
	dl money, lixi;
	cin >> money >> lixi;
	money += (money * (lixi / 100)) - 0.2 * (money * (lixi / 100));
	printf("%.2lf", money);
	return 0;
} 
