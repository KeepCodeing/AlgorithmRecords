#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 水完这题就70AC了... 

int main() {
	int arr[3];
	char c[3];
	for (int i = 0; i < 3; i++) cin >> arr[i];
	for (int i = 0; i < 3; i++) cin >> c[i];
	sort(arr, arr + 3);
	// 主要是题目给出了关系式，A<B<C，如果将ABC转换为下标，可知
	// 最小为A，最大为C， 对数组排序后将ABC转换为下标，即可得到答案 
	// 用字符减就行 
	cout << arr[abs('A' - c[0])] << ' ' << arr[abs('A' - c[1])] << ' ' << arr[abs('A' - c[2])];
	return 0;
}
