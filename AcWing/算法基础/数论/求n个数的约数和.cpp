#include <iostream>
#include <map>
using namespace std;

// ˼·�����ͺ���Լ��������࣬ͬ��������������ӳ��ֵĴ���
// Ȼ���������������������ƽ����1��

// ����Լ��d��������a��ָ��������Լ���ͣ�n 
// Լ��֮��n = (d^a + 1)*... 

const int mod = 1e9 + 7;
typedef long long LL;
map<int, int > m;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 2; i <= x / i; i++) {
			while (!(x % i)) {
				m[i]++;
				x /= i;
			}
		}
		if (x > 1) m[x]++;
	}
	LL res = 1;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
		int p = it->first, a = it->second;
		LL t = 1;
		// �����������������Ӹ����η� 
		while (a--) t = (t * p + 1) % mod;
		// �𰸾��Ǹ�������������Ӹ����η�ֻ�� 
		res *= t % mod;
	}
	cout << res;
	return 0;
}

/*
��������
3
2
6
8

�������
252
*/ 
