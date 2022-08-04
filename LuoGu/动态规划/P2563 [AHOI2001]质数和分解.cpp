#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��ȫ�����󷽰���,DP����Ŀ�����仯�ܴ󣬻�����һ����������������Ŀ�ĸо���
// �����Ҳ�����⣬���ڱ������������Ҫ����׼ʲô�Ǳ����ݻ���ʲô����Ʒ��ֵ��ʲô��
// ��Ʒ����...

// ����⻹Ҫע�������������У������Լ���������Լ������Բ�����ô����������ɷ�����Ҫ��һ�� 

typedef long long LL;
const int N = 220;
LL f[N];
vector<int > primes;
bool prs[250];
void getPrimes() {
	fill(prs, prs + 250, false);
	prs[0] = prs[1] = true;
	for (int i = 2; i <= 210; i++) {
		if (prs[i]) continue;
		primes.push_back(i); 
		for (int j = i * 2; j <= 210; j += i) {
			prs[j] = true;
		}
	}
}
int findNum(int num) {
	return lower_bound(primes.begin(), primes.end(), num) - primes.begin();
}
int main() {
	getPrimes();
	// for (int i = 0; i < primes.size(); i++) cout << primes[i] << endl;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int num;
	while (cin >> num) {
		fill(f, f + N, 0);
		f[0] = 1;
		for (int i = 0; i < findNum(num); i++) {
			for (int j = primes[i]; j <= num; j++) {
				f[j] += f[j - primes[i]];
			}
		}
		// ���������ܶ�һ����ɷ��� 
		cout << f[num] + !prs[num] << endl;
	}
	return 0;
} 
