#include <iostream>
using namespace std;
long long *arr;
int main() {
	int n;
	cin >> n;
	arr = new long long[n + 1];
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	cout << arr[n - 1];
	delete[] arr;
	return 0;
}
