#include <iostream>
using namespace std;
int *arr;
int main() {
	int n;
	cin >> n;
	arr = new int[50000];
	int t;
	int i = 0;
	while (cin >> t) {
		arr[i] = t;
		i++;
	}
	bool flag = true;
	int cnt = 0;
	for (int q = 0; q < i; q++) {
		for (int j = 0; j < arr[q]; j++) {
			if (flag) cout << '0';
			else cout << '1';
			cnt++;
			if (cnt == n && q != i - 1) {
				cout << endl;
				cnt = 0;
			}
		}
		flag = !flag;
	}
	delete[] arr;
	return 0;
}
