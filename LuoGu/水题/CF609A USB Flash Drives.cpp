#include <iostream>
#include <algorithm>
using namespace std;

// 水题第七弹，上一个水题因为核酸检测加自己太能摸了迟迟未完成...那么这个题就是个最基本的贪心了，不过即使如此
// 有关贪心的题目还是做得相当的少... 

const int N = 110;
int usb[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> usb[i];
	sort(usb, usb + n);
	int res = 0;
	while (m > 0) m -= usb[--n], res++;
	cout << res;
	return 0;
}
