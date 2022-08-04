#include <iostream>
using namespace std;
int *arr;
int main() {
	int n, cnt = 0;
	long m, temp = 0;
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		temp += arr[i];
		if (temp >= m) {
			temp = 0;
			cnt++;
		}
	}
	cout << cnt;
	delete[] arr;
	return 0;
} 
