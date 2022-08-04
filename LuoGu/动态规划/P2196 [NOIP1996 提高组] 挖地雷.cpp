#include <iostream>
#define endl '\n'
using namespace std;
const int N = 20 + 10;
int cast[N];
int mp[N][N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cast[i];
	for (int i = 0; i < n - 1; i++) {
		mp[i][i] = 1;
		for (int j = 0; j <= i; j++) {
			cin >> x;
			
		}
	}
	return 0;
}
