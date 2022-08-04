#include <iostream>
#include <cmath>
using namespace std;
const int N = 32767 + 10;
bool primes[N];
void getprime() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	int n, cnt = 0;
	cin >> n;
	getprime();
	// ���ӳ��ˣ�û�뵽��ôȥ�أ�������ʽö��֮ǰҲö�ٹ����Ե�...����Ҫ�Ƿ�Χ�����ˣ�֮ǰд��N��Ҳ���ǰ�����
	// ������ö�ٱ飬Ȼ��ͳ�����cnt = n * 2 - 1���������ͱȽ�����w����Ϊ�������ظ�����..��������setȥ��w... 
	for (int i = 1; i <= n / 2; i++) {
		// �����ǰ����һ���������ж�n - ��������ǲ��ǻ��Ǹ�����... 
		if (!primes[i] && !primes[n - i]) cnt++; 
	}
	cout << cnt;
	return 0;
}
