#include <iostream>
using namespace std;

// 水题，然而好笑的是其之前甚至没有想过要做..看到题面就溜了w 

int my_abs (int m) {
	return m < 0 ? -m : m;
}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	// 统一转换为分钟，再转换为小时/分钟 
	a *= 60, c *= 60;
	a += b, c += d;
	int m = my_abs(a - c);
	// 前者转为小时，后者取余拿到分钟... 
	cout << (int)(m / 60) << ' ' << m % 60;
	return 0;
}
