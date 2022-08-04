#include <iostream>
#include <vector>
using namespace std;

// ��Ŀ���˸��Ȱ��������������ʾ��ȷʵ������

bool primes[10010];
// ������������ʸ�� 
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
		// �ֽ��������Ĺؼ�while num % ���� == 0, num /= ����
		temp = i;
		cout << i << "=";
		for (int j = 0; j < p.size(); j++) {
			// ���Ӱ�����д�� % j... 
			while (!(temp % p[j])) {
				// �ж��ǲ��ǵ�һ��Ԫ�أ��ǾͲ������*
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
