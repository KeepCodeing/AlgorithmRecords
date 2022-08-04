#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
const int N = 1000 + 10;
typedef long long LL;
typedef pair<LL, LL > PII;
PII e[N];

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	char t;
	int fz = 0, fm = 0, cnt = 0;
	LL nfm = 1, nfz = 0;
	bool flag, fu;
	while (cin >> t) {
		if (t == '/') {
			flag = true;
			continue;
		}
		
		if (t == '+' || t == '-' && fz != 0 && fm != 0) {
			if (fu) fz = -fz;
			if (t == '-') fu = true;
			else fu = false;
			
			nfm *= fm;
			e[cnt++] = PII(fz, fm);
			
			fm = 0, fz = 0;
			flag = false;
			continue;
		}
		if (!flag) fz = fz * 10 + (t - '0');
		else fm = fm * 10 + (t - '0');
	}
	if (fu) fz = -fz;
	e[cnt++] = PII(fz, fm);
	
	nfm *= fm;
	
	for (int i = 0; i < cnt; i++) e[i].first *= nfm / e[i].second, e[i].second = nfm;
	
	for (int i = 0; i < cnt; i++) nfz += e[i].first;
	
	LL tgcd = gcd(abs(nfz), abs(nfm));
	
	if (nfz < 0 && nfm < 0) nfz = -nfz, nfm = -nfm;
	
	nfz /= tgcd, nfm /= tgcd;
	if (nfz % nfm == 0) cout << nfz / nfm << endl;
	else cout << nfz / tgcd << '/' << nfm / tgcd;
	
//	for (int i = 0; i < cnt; i++) cout << e[i].first << ' ' << e[i].second << endl;
	return 0;
}
