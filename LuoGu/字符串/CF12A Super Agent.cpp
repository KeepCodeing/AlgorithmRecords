#include <iostream>
using namespace std;

// 虽然是水题，但是保存快了就保存到字符串了...类似的题也见过了，不过那时候不会..所谓中心对称即该字符串
// 转换为一维之后是个回文串... 

int main() {
	string str, t;
	for (int i = 0; i < 3; i++) cin >> t, str += t;
	int left = 0, right = str.size() - 1;
	while (left < right) {
		if (str[left++] != str[right--]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
