#include <iostream>
using namespace std;
typedef long long LL;
const int N = 67;
LL res[N][N];
int main() {
	// ∏¥‘”∂»O(n^2) 
	for (int i = 0; i < N; i++) res[i][0] = res[i][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i / 2; j++) {
			res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
			res[i][i - j] = res[i][j]; 
		}
	}
	return 0;
}
