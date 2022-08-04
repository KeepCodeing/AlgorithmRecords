#include <iostream>
using namespace std;

// 算半个模板题..不知道会不会爆
// 没有爆w，那么今天就把普及题做到100道了..今天做了四个题，只有两个AC了... 

const int N = 5000 + 10;
int f[N][N]; 
int main() {
	string a, b;
	cin >> a >> b;
	int aLen = a.size(), bLen = b.size();
	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[aLen][bLen];
	return 0;
}
