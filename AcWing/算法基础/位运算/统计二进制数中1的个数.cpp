#include <iostream>
using namespace std;

// 原理：给定一个x，如果10，它的二进制就是 1010，将它取反，得到 0110（反码，
// 0101 + 1 = 0110，原数取反加一），这样就可以使x的第一位1后面的所有二进制数完全相反，从而
// 达到获取第一个1的目的。再利用原数减去最后一个1，并且统计x>0前有多少个1即可 
 
int lowbit(int x) {
	return x & -x;
}
// 模拟短除法也可以做 
int getOne(int x) {
	int t, cnt = 0;
	while (x) {
		t = x % 2;
		//x %= 2;
		if (t) cnt++;
		x >>= 1;
	}	
	return cnt;
} 
int main() {
	int n;
	cin >> n;
	int t, cnt;
	while (n--) {
		cnt = 0;
		cin >> t;
		// while (t) t -= lowbit(t), cnt++;
		cout << getOne(t) << ' ';
	}
	return 0;
}
