#include <iostream>
using namespace std;

// %1000��/10���������Ƽ��ɣ���������ڳ���û�����No�����ܣ�
// ��ô����ö�ٱ�����������ȫȫ������ 

int main() {
	int k;
	int a, b, c, t;
	bool flag = false;
	cin >> k;
	for (int i = 10000; i <= 30000; i++) {
		t = i;
		a = t % 1000;
		t /= 10;
		b = t % 1000;
		t /= 10;
		c = t;
		if (!(a % k) && !(b % k) && !(c % k)) cout << i << endl, flag = true;
	}
	if (!flag) cout << "No";
	return 0;
}
