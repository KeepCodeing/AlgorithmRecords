#include <iostream>
using namespace std;

int reverseNum(int x) {
	// 本来打算翻转的，但是处理后面的0比较麻烦，还是用字符串流算了
	// 谔谔，完全不用处理，因为如果后面是0不对res起作用，对res起作用的
	// 是第一个非0的数字，而有了这个非0数字该数字前有什么都无所谓了 
	int res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	} 
	return res;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << reverseNum(reverseNum(a) + reverseNum(b));
	return 0;
}
