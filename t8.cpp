#include <iostream>
#define endl '\n'
using namespace std;
)((
()(())


const int N = 1000;
typedef unsigned long long LL;
LL nums[N][N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	LL n;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			cnt++;
			if (j == 1 || j == i) nums[i][j] = 1;
			else nums[i][j] = nums[i - 1][j] + nums[i - 1] [j - 1];
			if (nums[i][j] == n) {
				cout << cnt << endl;
				return 0;
			}
		}
	}
	return 0;
}
