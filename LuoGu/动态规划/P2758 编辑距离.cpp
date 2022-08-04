#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

// 关于这个题的下标问题：最好从1开始，因为从0开始边界就变成-1了，如果意外访问到就会re之类的...
// 另外所有dp题的下标最好都从1开始... 

string a, b;
const int N = 2000 + 10;
int f[N][N];

int dfs(int i, int j) {
	
	// 返回要写在最前面（如果下标不管怎么样都是合法的） 
	if (f[i][j] != -1) return f[i][j];
	
	// 如果两个字符串为空，那么想要成为另一个字符串的方法就是将另一个字符串给复制过来，也就要另一个
	// 字符串的长度次操作
	if (i == 0) return f[i][j] = j;
	if (j == 0) return f[i][j] = i;
	
	// if (f[i][j] != -1) return f[i][j];
	
	int c = 1;
	
	if (a[i] == b[j]) c = 0;
	
	// 分开写似乎会出错... 
	return f[i][j] = min(min(dfs(i - 1, j) + 1, dfs(i, j - 1) + 1), dfs(i - 1, j - 1) + c);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	// 不知道为什么下标从0开始得不到正确答案，所以在前面加了个空字符让下标从1开始算... 
	// 可能的原因是i = -1时j = -1之类的，这种会re，所以要保证下标不管怎么样都能访问...
	a = " " + a;
	b = " " + b;
	int aLen = a.size(), bLen = b.size();
	
	memset(f, -1, sizeof(f));
	cout << dfs(aLen, bLen) << endl;
	// 答案通过dp表得到，直接通过函数似乎也是可以的... 
	// cout << f[aLen][bLen];
	return 0;
}
