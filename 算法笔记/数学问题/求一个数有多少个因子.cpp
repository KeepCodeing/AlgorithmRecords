#include <iostream>
using namespace std;
typedef long long LL;
LL fac;
const int N = 100;
int bucket[N];
int main() {
//	fac = 1;
//	for (int i = 1; i <= 10; i++) fac *= i;
//	for (int i = 2; i <= fac / i; i++) {
//		while (!(fac % i)) {
//			bucket[i]++;
//			fac /= i;
//		}
//	}
//	if (fac > 1) bucket[fac]++;
	LL res = 1;
	for (int i = 1; i <= 100; i++) {
		int temp = i;
		for (int j = 2; j <= temp / j; j++) {
			while (!(temp % j)) {
				bucket[j]++;
				temp /= j;
			}
		}
		if (temp > 1) bucket[temp]++;
	}
	
	for (int i = 0; i < 100; i++) {
		if (bucket[i] != 0) res *= (bucket[i] + 1);
	}
	cout << res << endl;
	return 0;
}
