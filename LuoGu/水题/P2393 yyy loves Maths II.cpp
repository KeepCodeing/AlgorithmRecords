#include <iostream>
#include <cstdio>
using namespace std;

// ��Ҫ�Ǿ������� 

long double sum = .0, num; 
int main() {
	while (cin >> num) {
		// ȫ��ת��Ϊ���� 
		sum += num*1000000;
	}
	// ��ԭС�� 
	printf("%.5Lf", sum/1000000);
	return 0;
}
