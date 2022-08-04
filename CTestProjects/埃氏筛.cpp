#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr;
	// 先标记为false，表示是素数 
	arr = new int[n]();
	// 两个坑，0和1不算素数
	arr[0] = arr[1] = true; 
	for (int i = 2; i <= n; i++) {
		// 如果是素数，将其倍数筛掉 
		if (!arr[i]) {
			// 注意这里，j=i*2和j+=1就是表示筛素数 
			for (int j = i * 2; j <= n; j += i) {
				// 筛掉素数的倍数 
				arr[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!arr[i]) cout << i << endl;
	}
	delete[] arr; 
	return 0;
}
