#include <iostream>
#include <vector>
using namespace std;

// 题目给了个先把质数求出来的提示，确实该这样

bool primes[10010];
// 用来放素数的矢量 
vector<int > p;
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 10010; i++) {
		if (!primes[i]) {
			p.push_back(i); 
			for (int j = i * 2; j <= 10010; j += i) {
				primes[j] = true;
			}
		}
	}
} 

int main() {
	getPrimes();
	int start, end;
	int temp;
	cin >> start >> end;
	for (int i = start; i <= end; i++) {
		// 分解质因数的关键while num % 因子 == 0, num /= 因子
		temp = i;
		cout << i << "=";
		for (int j = 0; j < p.size(); j++) {
			// 池沼把这里写成 % j... 
			while (!(temp % p[j])) {
				// 判断是不是第一个元素，是就不用输出*
				if (temp == i) cout << p[j];
				else cout << "*" << p[j];
				temp /= p[j];
			}
			if (!temp) break;
		}
		cout << endl;
	}
	return 0;
}
