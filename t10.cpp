#include <iostream>
#define endl '\n'
using namespace std;
void dfs(int l, int r, string res) {
	
	if (l == 0 && r == 0) {
		cout << res << endl;
		return;
	}
	
	if (l >= 0) dfs(l - 1, r, res + '(');
	if (r > l && r >= 0) dfs(l, r - 1, res + ')');
}

typedef unsigned long long LL;
const int N = 5000 + 10;
const LL M = 1e9 + 7;
LL f[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string str;
	cin >> str;
	int l = 0, r = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') l++;
		else r++;
	}
	int n = max(l, r);
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = (f[i - 1] % M) * ((i * 4) % M - 2) / (i + 1) % M;
	}
	cout << f[n];
	return 0;
}
