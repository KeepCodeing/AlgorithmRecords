#include <iostream>
using namespace std;

// ֮ǰ�İ���������w��������Ӳ���������ͬ�෽�̽������... 

typedef long long LL;
void exgcd(LL a, LL b, LL&x ,LL& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return;
}
int main() {
	LL a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << (x % b + b) % b;
	return 0;
}
