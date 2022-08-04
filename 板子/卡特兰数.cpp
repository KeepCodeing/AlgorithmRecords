#include <iostream>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 50;
LL f[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	f[0] = f[1] = 1;
	for (int i = 2; i <= 10; i++) f[i] = f[i - 1] * (i * 4 - 2) / (i + 1), cout << f[i] << endl;
	
	return 0;
}
