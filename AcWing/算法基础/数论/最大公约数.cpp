#include <iostream>
using namespace std;

// շת����������a % b����0��a��Ϊ��Сֵb����b��Ϊa % b������
// ����ֱ��bΪ0�ˣ�a�������Լ�� 

// շת�����ʱ�临�Ӷ�Ϊlog(n)������Ч�ʺܸ� 

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	} 
	return 0;
}
/*
��������
2
3 6
4 6

�������
3
2
*/
