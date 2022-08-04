#include <iostream>
#define endl '\n'
using namespace std;

// 坠毁，思路大体是正确的，但是怎么求最短的出去的时间这块错乱...这里给出的记忆化最多能求出不能逃脱但最多能走多远的情况，
// 而不能求出能够逃脱用时最短的情况...原因在于这个题要先用贪心把能闪的机会都先用了节省空间并且减少时间复杂度...（如果
// 直接开这么大的数组空间会爆...） 

const int N = 300000 + 10, M = 1000 + 10;
int f[N][M];
int m, s, tm;
int mtm = N, far = 0;
int dfs(int t, int m, int far) {
	
	if (t <= 0) return 0;
	
	if (f[t][m]) return f[t][m];
	
	if (far >= s) {
		cout << tm - t - 1<< endl;
	}
	
	// 算出当时间为t，法力值为m时能走的最远距离 
	if (m - 10 >= 0) f[t][m] = max(f[t][m], dfs(t - 1, m - 10, far + 60) + 60);
	f[t][m] = max(f[t][m], dfs(t - 1, m, far + 17) + 17);
	f[t][m] = max(f[t][m], dfs(t - 1, m + 4, far));
	
	return f[t][m];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> s >> tm;
	far = dfs(tm, m, 0);
//	if (mtm != N) {
//		cout << "Yes" << endl;
//		cout << t - mtm;
//		return 0;
//	}
//	cout << "No" << endl;
//	cout << far << endl;
	
	return 0;
}
