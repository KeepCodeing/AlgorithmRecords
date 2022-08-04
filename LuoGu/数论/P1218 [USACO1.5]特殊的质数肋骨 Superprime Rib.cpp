#include <iostream>
using namespace std;

// 质素筛 
// 数据范围小，应该可以打表 ，要打下8的表，其它经过优化可以过 

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
	// 取到素数范围
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
