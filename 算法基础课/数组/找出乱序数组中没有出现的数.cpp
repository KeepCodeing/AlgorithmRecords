#include <iostream>
#include <algorithm>
using namespace std;
// ˼·�������������������⣨�����⣬��֪������ʲô��ʽ�� 
int main() {
	int arr[10] = {5, 3, 1, 9 ,8, 2, 11, 4, 6, 7};	
	sort(arr, arr + 10);
	int x = 0;
	for (int i = 1; i <= arr[9]; i++) {
		x ^= i;
	}
	for (int i = 0; i <= 9; i++) {
		x ^= arr[i];
		cout << x << ' ';
	}
	cout << endl << x << endl;
	return 0;
}
