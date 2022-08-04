#include <iostream>
using namespace std;

// 主要还是利用模拟短除法求k进制 

// 转换进制+判断是否是回文的函数 
bool isPrime(int n, int k) {
	int res[35], index = 0;
	// 这样转出来的是个反的，不过无所谓，因为回文
	// 数是对称的，所以下面可以用个双指针判断下 
	while (n) {
		res[index++] = n % k;
		n /= k;
	}
	// 二到十进制的数，所以不用考虑字母什么的 
	// for (int i = index - 1; i >= 0; i--) cout << res[i];
	int left = 0, right = index - 1;
	while (left < right) {
		if (res[left++] != res[right--]) return false;
	}
	return true;
}
int main() {
	int n, s, cnt;
	cin >> n >> s;
	while (true) {
		if (n <= 0) break;
		s++, cnt = 0;
		for (int i = 2; i <= 10; i++) {
			if (isPrime(s, i)) cnt++;
		}
		// 如果是双重回文数，输出并减少n 
		if (cnt >= 2) cout << s << endl, n--;
	}
	return 0;
}
