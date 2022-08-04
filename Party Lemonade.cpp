#include <iostream>
#include <algorithm>
#define endl '\n'
#define x first
#define y second
using namespace std;

typedef pair<int, int > PII;

const int N = 35;
int ml[N];
PII pirs[N];
int quick_power(int p, int q) {
	int res = 1;
	while (q) {
		if (q & 1) res = res * 1ll * p;
		q >>= 1;
		p *= p;
	}
	return res;
}


int main() {
	cout << 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 32; i++) ml[i] = quick_power(2, i - 1);
	int n, l, c;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> c, pirs[i] = PII(c, ml[i]);
	sort(pirs + 1, pirs + n + 1);
	
	return 0;
}
