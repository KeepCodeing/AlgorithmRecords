#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// 已知汉诺塔的移动步数为2^n - 1，这个题目数据量较大，需要高精度加法，或许还可以加个
// 快速幂

// 快速幂忘的差不多了，总结下就是q^n，n有多少位1，q就乘自己多少次 
void ksm(int n) {
	int r = 2, q = n;
	int res = 1;
	while (q) {
		if (q & 1) res = res * 1ll * r;
		q >>= 1;
		r = r * 1ll * r;
	} 
	cout << res;
} 

int main() {
	int n;
	cin >> n;
	// 更加快捷的方法（仅适用于计算2^n且|n|<2^14
	// 利用字符串流转换
	stringstream ss;
	ss.precision(0);
	ss << fixed << pow(2.0L, n);
	// 转换为字符串 
	string s = ss.str();
	s[s.size() - 1]--;
	cout << s << endl;
	return 0;
}
