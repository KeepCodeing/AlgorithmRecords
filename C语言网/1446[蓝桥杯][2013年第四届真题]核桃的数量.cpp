#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	// ��Ҫ��ע��0������������������Ҳ���Լ��뵽�Ӱ�����
	// ȫ����ȵ���� 
	if (a == b && b == c) {
		cout << a;
		return 0;
	}
	for (int i = 1; i <= 10000000; i++) {
		// ���ֵܷ���ע���Ǵ�С����ģ 
		if (i % a == 0 && i % b == 0 && i % c == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}
