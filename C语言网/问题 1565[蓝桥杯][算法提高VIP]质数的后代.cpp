#include <iostream>
using namespace std;
bool primes[100010];
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= 100010; i++) {
		if (primes[i]) continue;
		for (int j = i * 2; j <= 100010; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getPrimes();
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		// ������������������ô�����Բ�����������������˵õ��� 
		if (!primes[x]) {
			cout << "No" << endl;
		} else {
			bool flag = false;
			// ö�������������� 
			for (int i = 2; i < x; i++) {
				if (!primes[i]) {
					// ����ת�� 
					float t = x * 1.0 / i;
					if ((int)t == t) {
						if (!primes[(int)t]) {
							cout << "Yes" << endl;
							flag = true;
							break;
						}
					}
				}
			}
			if (!flag) cout << "No" << endl;
		}
	} 
	return 0;
}
