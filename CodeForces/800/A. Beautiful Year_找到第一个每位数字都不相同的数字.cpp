#include <iostream>
using namespace std;

// ��20��ˮ�⣬�����������渴ϰ...���������һ���ˮ����w.. 

bool checker(int n) {
	int a, b, c, d;
	a = n / 1000, b = n / 100 % 10, c = n / 10 % 10, d = n % 10;
	return a != b && a != c && a != d && b != c && b != d && c != d;
}
int main() {
	int n;
	cin >> n;
	while (true) {
		// �ϸ���� 
		n += 1;
		if (checker(n)) {
			cout << n << endl;
			break;
		}
	}
	return 0;
}
