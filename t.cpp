#include <iostream>
using namespace std;

const int N = 110, M = 1110;



long long f[M];
int num[M];


int main() {
	int n ;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> num[i];
	
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (f[i] > f[j]) {
				f[j] = max(f[i], f[j] + 1);
			}
		}
	}
	
	return 0;
}
