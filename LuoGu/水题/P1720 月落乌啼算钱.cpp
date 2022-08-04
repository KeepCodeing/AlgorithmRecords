#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// Ð´¹«Ê½.. 

int main() {
	int n;
	cin >> n;
	printf("%.2lf", (pow((1.0 + sqrt(5)) / 2, n) - pow((1.0 - sqrt(5)) / 2, n)) / sqrt(5));
	return 0;
}
