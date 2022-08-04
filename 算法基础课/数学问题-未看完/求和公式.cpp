#include <iostream>
using namespace std;
// 等差数列的求和公式
// 如2 4 6 8 10这种数列，d=2，由此可得sn = n*(n + 1)/2，an = a1 + (n-1)*d 
int dcsl() {
	int n = 10;
	int arr[n];
	for (int i = 1; i <= n; i++) arr[i - 1] = i;
	// int d = arr[1] - arr[0];
	// int a10 = arr[0] + (n - 1) * d;
	int sn = (n * (n + 1)) / 2;
	return sn;
} 
// 平方和公式
// 如1^2 + 2^2 + 3^2 + 4^2这种数列，它的求和公式为n*(n + 1)*(2*n + 1) / 6 
int pfh(int n) {
	return (n*(n + 1)*(2*n + 1)) / 6;
}
// 立方和公式
// 如1^3 + 2^3 + 3^3 + 4^3这种数列，它的求和公式为n^2(n + 1)^2 / 4
int lfh(int n) {
	return ((n*n)*((n + 1)*(n + 1))) / 4;
}
// 等比数列的求和公式
// 如1, 2, 4, 8..这种类型的数列为等比数列，该数列q=2，等比数列的求和公式是(a1*(1 - q^n)) / 1-q 
int dbsl(int a1, int q, int n) {
	int qn = q;
	for (int i = 1; i < n; i++) qn *= q;
	return (a1*(1 - qn)) / (1-q); 
}
// 调和级数的求和公式
// 形如1/1+1/2+1/3+…+1/n+…的级数称为调和级数，只能求其近似值，暂未找到公式 
int main() {
	cout << dbsl(1, 2, 3);
	return 0;
}
