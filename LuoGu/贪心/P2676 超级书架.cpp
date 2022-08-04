//#include <iostream>
//#include <map>
//using namespace std;
//
//// 看起来就是个排序的题，可以用桶排
// 
//// 用个map当桶 
//map<int, int > m;
//int main() {
//	int n, temp;
//	int cnt = 0;
//	long long h;
//	cin >> n >> h;
//	for (int i = 0; i < n; i++) {
//		cin >> temp;
//		// 特判，不知道会不会有这种数据 
//		if (temp >= h) {
//			cout << 1;
//			return 0;
//		}
//		m[temp]++;
//	}
//	// 坠毁，改用sort 
//	for (map<int, int >::iterator it = --m.end(); it != m.begin(); it--) {
//		h -= it->first * it->second;
//		cnt++;
//		if (h <= 0) break;
//	}
//	cout << cnt;
//	return 0;
//}
// 桶排不知道是哪里写错了 
#include <iostream>
#include <algorithm>
using namespace std;
int *arr;
int main() {
	int n, temp;
	int cnt = 0;
	long long h;
	cin >> n >> h;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// 特判，不知道会不会有这种数据 
		if (arr[i] >= h) {
			cout << 1;
			return 0;
		}
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		h -= arr[i];
		cnt++;
		if (h <= 0) break;
	}
	cout << cnt;
	delete[] arr;
	return 0;
}
