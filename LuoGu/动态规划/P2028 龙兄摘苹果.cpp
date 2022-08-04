#include <iostream>
#define endl '\n'
using namespace std;

const int N = 10000 + 10, M = 1000 + 10;
typedef long long LL;

LL dfs(int l, int b) {
	
	dfs(l - 1, b);
	dfs(l, b - 1);
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k, p;
	cin >> n >> k >> p;
	
	return 0;
}
