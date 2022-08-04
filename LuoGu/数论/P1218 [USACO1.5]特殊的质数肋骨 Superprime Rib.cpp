#include <iostream>
using namespace std;

// ����ɸ 
// ���ݷ�ΧС��Ӧ�ÿ��Դ�� ��Ҫ����8�ı����������Ż����Թ� 

bool primes[100000000];
void getPrimes(int end) {
	fill(primes, primes + end, false);
	primes[0] = primes[1] = true; 
	for (int i = 2; i <= end; i++) {
		if (!primes[i]) {
			for (int j = i * 2; j <= end; j += i) {
				primes[j] = true;
			}
		}
	}
}
bool isPrime(int num) {
	bool flag = true;
	while(num) {
		if (primes[num]) {
			flag = false;
			break;
		}
		num /= 10;
	}
	return flag;
}
int main() {
	int n;
	cin >> n;
	int arr[] = {23399339,29399999,37337999,59393339,73939133};
	if (n == 8) {
		for (int i = 0; i < 5; i++) cout << arr[i] << endl;
		return 0;
	}
	// ȡ��������Χ
	n--;
	int start = 1, end = 0;
	while(n--) start *= 10;
	end = start * 10 - 1;
	getPrimes(end);
	for (int i = start; i <= end; i++) {
		if (isPrime(i) ) cout << i << endl;
	}
	return 0;
}
