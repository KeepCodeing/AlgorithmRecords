#include <iostream>
#include <cmath>
using namespace std;
int *arr;
int main() {
	int n, temp;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		temp = abs(arr[i] - arr[i + 1]);
		if (1 > temp || temp > n - 1) {
			cout << "Not jolly";
			return 0;
		}
	}
	cout << "Jolly";
	return 0;
}
