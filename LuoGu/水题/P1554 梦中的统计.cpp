#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int arr[10] = {0};
	for (int i = m; i <= n; i++) {
		int temp = i;
		while (temp) {
			// 这里比较巧妙，看起来统计数字字符个数可以用这种方法
			// 而不是搞个字符串什么的 
			arr[temp % 10]++;
			temp /= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
		if (i != 9) cout << ' ';
	}
	return 0;
}
