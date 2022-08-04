#include <iostream>
#define endl '\n'
using namespace std;
typedef unsigned long long LL;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	LL n;
	cin >> n;
	n %= 86400000;
	int shi, fen, miao, hmiao;
	shi = fen = miao = hmiao = 0;
	while (n) {
		n--;
		hmiao++;
		if (hmiao >= 1000) miao++, hmiao = 0;
		if (miao >= 60) fen++, miao = 0;
		if (fen >= 60) shi++, fen = 0;
	}
	if (shi < 10) cout << 0;
	cout << shi << ':';
	if (fen < 10) cout << 0;
	cout << fen << ':';
	if (miao < 10) cout << 0;
	cout << miao;
	return 0;
}
