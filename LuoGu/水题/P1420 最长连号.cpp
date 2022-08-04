#include <iostream>
using namespace std;

// 感觉有点像最长上升子序列那个题 （谔谔，完全不需要结构体什么的） 

int *arr;
//struct number {
//	int h, l;
//	number(int h1 = 0, int l1 = 0) {
//		h = h1, l = l1;
//	}
//};
int main() {
	int n;
	// 防止漏掉最后一个数 
	int cnt = 1;
	int maxCnt = 0;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] + 1 == arr[i + 1]) cnt++;
		else maxCnt = cnt > maxCnt ? cnt : maxCnt, cnt = 1;
		// cout << arr[i] << ' ' << arr[i + 1] << endl;
	}
	cout << maxCnt;
	delete[] arr;
	return 0;
}
