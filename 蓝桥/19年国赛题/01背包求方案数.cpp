#include <iostream>
#include <cmath>
using namespace std;

// �����˲���û��һ�۷����Ǹ�01����...�ȴ��������Ȼ��long long
// �׷�������... 

typedef long long LL;
const int N = 3000, M = 2019;
bool primes[N];
LL f[N];
void getprimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getprimes();
	f[0] = 1;
	// ����ģ�Ϳ������ˣ�ָϸ�ڣ����о�Ҫ��ϰ���ˣ�ʹ���У�... 
	for (int i = 0; i < N; i++) {
		if (primes[i]) continue;
		for (int j = M; j >= i; j--) {
			f[j] += f[j - i];
		}
	}
	cout << f[2019];
	return 0;
}
