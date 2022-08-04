#include <iostream>
using namespace std;
// 草，是个类似滑动窗口的题，不是说隔m个加 
int *arr;

int main() {
	int n, m, minNum = 1145141919, tMin = 0;
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= n - m; i++) {
		tMin = 0;
		for (int j = i; j < i + m; j++) {
			tMin += arr[j];
		}
		
		minNum = min(minNum, tMin);
	}
	cout << minNum;
	delete[] arr;
	return 0;
}
