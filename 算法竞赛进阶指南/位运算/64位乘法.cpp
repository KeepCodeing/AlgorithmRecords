#include <iostream>
using namespace std;

// �Ϳ����ݲ�࣬������������0<=a,b<=10^16������ø߾���ʵ�־ͱȽ��鷳������
// ͬ�������ÿ����ݵ�˼����

typedef unsigned long long ULL; 

int main() {
	// �ӵ����������� 
	ULL a, b, q;
	cin >> a >> b >> q;
	ULL res = 0;
	while (b) {
		if (b & 1) res = (res + a) % q;
		b >>= 1;
		// a+a�͵���a*2���Ϳ����ݻ�����࣬���ǰѳ˸�Ϊ�˼� 
		a = a * 2 % q; 
	}
	cout << res;
	return 0;
} 
