#include <iostream>
#include <cmath>
using namespace std;

// ���ȣ�ö��ֻ��ö�ٵ�sqrt(n)����Ϊ����sqrt(n)�������ܻᱻɸ��������˵��sqrt(100) = 10�����ѷ������Ǵ�20ö����ɸȥ����һ����5ɸ�� 
// �������ɸ���������������Ͳ���ɸ�ˣ������Ż����Դﵽn*loglogn�ĸ��Ӷ� 
// ����ɸ����Ȼ�ܹ������ٵ�ɸ����Χ�ڵ����������ǲ�������ͳ�Ʒ�Χ�ڵ�������������ͳ����������ɨ��������Χ�ڵ�����Ҳ��������
// �İ���ɸ����ɸ���� 

const int N = 1e7;
bool primes[N];
int main() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			primes[j] = true;
		}
	}
	for (int i = 0; i < 1e3; i++) if (!primes[i]) {
		cout << i << endl;
	}
	return 0;
}
