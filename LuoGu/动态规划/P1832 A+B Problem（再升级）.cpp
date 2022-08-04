#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���ر����󷽰���

const int N = 1010;
bool primes[N];
vector<int > vec;
void getPrime() {
	for (int i = 2; i <= N; i++) {
		if (primes[i]) continue;
		vec.push_back(i); 
		for (int j = i *2; j <= N; j += i) {
			primes[j] = true;
		}
	}
}
// û��long long׹����һ��ww 
long long f[N];
int main() {
	getPrime();
	int n;
	cin >> n;
	int idx = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
	f[0] = 1;
	// ��Ʒ��������С�ڵ��ڸ���������������ע������Ҫ����������Լ� 
	for (int i = 0; i <= idx; i++) {
		// ��Ʒ��ֵ���ǵ�ǰ���� 
		for (int j = vec[i]; j <= n; j++) {
			f[j] += f[j - vec[i]];
		}
	}
	cout << f[n];
	return 0;
} 
