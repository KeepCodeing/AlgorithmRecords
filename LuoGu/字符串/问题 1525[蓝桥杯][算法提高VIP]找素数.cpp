#include <iostream>
using namespace std;

// ����ɸ��������Ϊ��Ҫǰ׺�͵ģ�����ֻ��һ��ѯ��
// �������䳤�Ⱥܴ󣬿��ܻ�Ҫ������ɢ������ʵ������Щ����������һ���
// ���Կ����ü�ȥl�ķ�ʽ����ý�С���±� 
 
bool *primes; 

void getPrimes(int l, int r) {
	primes[0] = primes[1] = true;
	for (int i = l; i <= 1000; i++) {
		if (primes[i - l]) continue;
		for (int j = i * 2; j <= 1000; j += i) {
			primes[j] = true;
		}
	}
}

int main() {
	int l, r;
	cin >> l >> r;
	primes = new bool[r - l + 10];
	fill(primes, primes + r - l + 10, false);
	getPrimes(l, r);
	for (int i = 0; i <= 1000; i++) {
		if (!primes[i]) cout << i + l << ' ';
	}
	delete[] primes;
	return 0;
} 
