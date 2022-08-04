#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ȼ����û����ȫ�������ww����Ŀ����˼��[2, n]�ڵ������������ڵ�����֮��+1Ҳ��������������Щ�����ĸ������ڵ���
// k�������YES���������NO 

const int N = 1010;
bool primes[N];
vector<int > vec;
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i <= N; i++) {
		if (primes[i]) continue;
		vec.push_back(i); 
		for (int j = i * 2; j <= N; j += i) {
			primes[j] = true;
		}
	}
}
int main() {
	getPrimes();
	int n, k;
	cin >> n >> k;
	int ans = 0, temp = 0;
	int vLen = vec.size();
	for (int i = 0; i < vLen - 1; i++) {
		// ͳ��[2, n]�����������������ڵ������Ͳ����ж�������ǲ������� 
		temp = vec[i] + vec[i + 1] + 1;
		if (temp > n) break;
		if (!primes[temp]) ans++;
	}
	if (ans >= k) cout << "YES";
	else cout << "NO";
	return 0;
}
