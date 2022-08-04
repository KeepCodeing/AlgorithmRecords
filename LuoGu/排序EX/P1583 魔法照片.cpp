#include <iostream>
#include <algorithm>
using namespace std;

// 还没太明白题意，先写写 
int *W;
int E[11], C[10];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, k;
	cin >> n >> k;
	W = new int[n];
	for (int i = 1; i <= 10; i++) cin >> E[i];
	for (int i = 0; i < n; i++) cin >> W[i];
	sort(W, W + n, cmp);
	for (int i = 0; i < n; i++) {
		C[i] = (W[i] - 1) % 10 + 1;
	}
	for (int i = 0; i < n; i++) {
		W[i] += E[C[i]];
	}
	sort(W, W + n, cmp);
	for (int i = 0; i < k; i++) {
		cout << W[i];
		if (i != n - 1) cout << ' ';
	}
	return 0;
}
