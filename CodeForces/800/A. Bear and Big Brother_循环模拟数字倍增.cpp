#include <iostream>
using namespace std;

// �ܺ��ϴ��ww������˼��title w���������a��ÿ������3�����أ�b��ÿ������2����Ȼ���ж�
// Ҫ����a > b... 

int main() {
	int a, b, cnt = 0;
	cin >> a >> b;
	while (true) {
		a *= 3, b *= 2, cnt++;
		if (a > b) break;
	}
	cout << cnt << endl;
	return 0;
}
