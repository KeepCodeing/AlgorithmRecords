#include <iostream>
using namespace std;
// ¡Æ(n - i) 1 <= i <= m
long long res = 0;
//int cnt = 0;
//vector<int > vec;
void dfs(int len, int pre, bool flag, int n) {
	if (len == 0) {
//		for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
//		cout << endl;
		res++, res %= 10000;
		return;
	}
	if (flag) {
		for (int i = 1; i < pre; i++) {
			//vec.push_back(i); 
			dfs(len - 1, i, !flag, n);
			//if (vec.size()) vec.pop_back(); 
		}
	} else {
		for (int i = pre + 1; i <= n; i++) {
			//vec.push_back(i); 
			dfs(len - 1, i, !flag, n);
			//if (vec.size()) vec.pop_back(); 
		}
	}
}
int main() {
//	int m, n;
//	cin >> m >> n;
//	long long t;
//	for (int i = 1; i <= m; i++) t += n - i, res += t % 10000, t % 10000;
//	for (int i = 2; i <= n; i++) {
//	if (m == n) {
//		
//	}
	//vec.push_back(2); 
	// 10 10
//	if (m == 1) {
//		cout << n;
//		return 0;
//	}
	// 2 10 45
	// 3 10 285
	// 1695
//	if (m == 10 && n == 10) {
//		cout << 3256;
//		return 0;
//	}
	for (int i = 11;; i++) {
		res = 0;
		for (int j = 1; j < i; j++) {
			dfs(i, 1, false, j);
			cout << i << ' ' << j << endl;
			cout << res << endl;
		}
	}
//	dfs(m, 1, false, n);
//	cout << res;
	return 0;
}
