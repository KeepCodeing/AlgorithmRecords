#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1000 + 10;
int f[N][N];

string str;
int sLen = 0;

int dfs(int i, int j) {
	
	if (f[i][j]) return f[i][j];
	
	if (i > j) return 0;
	
	int c = 2;
	
	if (str[i] == str[j]) c = 0;
	
	return f[i][j] = min(min(dfs(i + 1, j) + 1, dfs(i, j - 1) + 1), dfs(i + 1, j - 1) + c);
	
} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> str;
	sLen = str.size();
	cout << dfs(0, sLen - 1);
	return 0;
}
