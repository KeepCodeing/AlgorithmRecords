//#include <iostream>
//#include <map>
//using namespace std;
//
//// ���������Ǹ�������⣬������Ͱ��
// 
//// �ø�map��Ͱ 
//map<int, int > m;
//int main() {
//	int n, temp;
//	int cnt = 0;
//	long long h;
//	cin >> n >> h;
//	for (int i = 0; i < n; i++) {
//		cin >> temp;
//		// ���У���֪���᲻������������ 
//		if (temp >= h) {
//			cout << 1;
//			return 0;
//		}
//		m[temp]++;
//	}
//	// ׹�٣�����sort 
//	for (map<int, int >::iterator it = --m.end(); it != m.begin(); it--) {
//		h -= it->first * it->second;
//		cnt++;
//		if (h <= 0) break;
//	}
//	cout << cnt;
//	return 0;
//}
// Ͱ�Ų�֪��������д���� 
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
		// ���У���֪���᲻������������ 
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
