#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 100 + 10;
char s1[N], s2[N];
int f[N][N];

int calt(char a, char b) {

	if (a == 'A' && b == 'A') return 5;
	if (a == 'A' && b == 'C') return -1;
	if (a == 'A' && b == 'G') return -2;
	if (a == 'A' && b == 'T') return -1;
	if (a == 'A' && b == '-') return -3;
	
	if (a == 'C' && b == 'C') return 5;
	if (a == 'C' && b == 'A') return -1;
	if (a == 'C' && b == 'G') return -3;
	if (a == 'C' && b == 'T') return -2;
	if (a == 'C' && b == '-') return -4;
	
	if (a == 'G' && b == 'G') return 5;
	if (a == 'G' && b == 'A') return -2;
	if (a == 'G' && b == 'C') return -3;
	if (a == 'G' && b == 'T') return -2;
	if (a == 'G' && b == '-') return -2;
	
	if (a == 'T' && b == 'T') return 5;
	if (a == 'T' && b == 'A') return -1;
	if (a == 'T' && b == 'C') return -2;
	if (a == 'T' && b == 'G') return -2;
	if (a == 'T' && b == '-') return -1;
	
	if (a == '-' && b == 'A') return -3;
	if (a == '-' && b == 'C') return -4;
	if (a == '-' && b == 'G') return -2;
	if (a == '-' && b == 'T') return -1;
	
//	if (a == b) return 5;
	
	// 注意这里要加个return 0，不然所有情况都不满足calt会返回一个不定值... 
	return 0;
}

int dfs(int i, int j) {
	
	if (f[i][j]) return f[i][j];
	
	if (i == 0 || j == 0) return 0;
	
	return f[i][j] = max(
		dfs(i - 1, j - 1) + calt(s1[i], s2[j]), 
		max(dfs(i - 1, j) + calt(s1[i], '-'), dfs(i, j - 1) + calt('-', s2[j]))
	);
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s1[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> s2[i];
	
	// 必须要加的边界条件，用来初始化i != 0, j == 0的情况，也就是s1只能和'-'配对，下面同理 
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i - 1][0] + calt(s1[i], '-');
	}
	for (int i = 1; i <= m; i++) {
		f[0][i] = f[0][i - 1] + calt(s2[i], '-');
	}
	
	cout << dfs(n, m);
	
	return 0;
}


