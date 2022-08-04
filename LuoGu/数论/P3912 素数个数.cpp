#include <iostream>
using namespace std;

// 1e8�����ݰ���ɸ��ȻҲ���Թ�...�������İ���ɸ��һ��д���İ���ɸ������ͬ������ֱ��ö�ٵ�i*i���������ܸ���
// ����Ч�ʰ� 
// ���׹��w����ʵ����Ǹ������°���ɸ��������Ƿ�������������Ȼ����������ȥ������
// ��������������������... 

// ����ö��i�ᳬʱһ���㣬���ö��i*i������2s������1e8�����ݣ����Կ�����������Ч�� 

const int N = 1e8 + 10;
bool primes[N];
int main() {
	int n;
	cin >> n;
	int res = n - 1;
	primes[0] = primes[1] = true;
	// �䶯1:�����i<=n�ĳ���i * i <= n�����ܰ�ʱ���Ż���log��... 
	for (int i = 2; i * i <= n; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			// �䶯2:�����ж����µ�ǰ���ǲ�����������������
			// ����ʹres�����Լ��������������Լ�����ɴ𰸴��� 
			if (!primes[j]) {
				primes[j] = true;
				res--;	
			}
			
		}
	}
	// for (int i = 0; i < n; i++) if (!primes[i]) cout << i << ' ';
	cout << res;
	return 0;
}
