#include <iostream>
using namespace std;

// ͬ�����ָa % m == b % m��ͬ�෽��������ax + ny = b�ķ��̣����ַ��̿�������չŷ������㷨��⣬����Ҫ���һ��.. 

/*
���ű��Ĵ����ƺ����������⣬Ҳ�������Լ�д���ˣ���֮û�в��Թ�������ը��... 
*/
// �������������չŷ������㷨
typedef long long LL;
void exgcd(LL a, LL b, LL&x, LL& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
} 
int main() {
	LL a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	printf("%lld", (x % b + b) % b);
	return 0;
}
//int exgcd(int a, int b, int& x, int& y) {
//	if (b == 0) {
//		x = 1, y = 0;
//		return a;
//	}
//	int r = exgcd(a % b, b, x, y);
//	int temp = y;
//	y = x + (a / b) * y;
//	x = temp;
//	return r;
//}
//int main() {
// 	int a, b, x, y;
// 	cin >> a >> b;
// 	exgcd(a, b, x, y);
// 	// ����չŷ������㷨�Ļ����ϵĸĽ��������Ͳ��÷ǵ�m��gcd(a, b)�ı������ܻ�ý���... 
//	x = (x + b) % b;
// 	cout << x <<endl;
// 	return 0;
// }
