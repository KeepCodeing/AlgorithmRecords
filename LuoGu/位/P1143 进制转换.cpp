#include <iostream>
#include <algorithm>
using namespace std;

// 思路：先把原进制数转化为十进制数，然后再用短除法把十进制转为答案进制.. 

// 将任意进制转换为10进制，转换公式为A进制从后往前第i个元素 * A^(i - 1)，依次循环...，比如1010(B)转10进制，
// 就是1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 10 
int any2d(string str, int n) {
	int sLen = str.size(), res = 0, pf = 1;
	for (int i = sLen - 1; i >= 0; i--) {
		if (str[i] >= 'A' && str[i] <= 'F') str[i] = str[i] - 'A' + '0' + 10;
		res += (str[i] - '0') * pf;
		pf *= n;
	}
	return res;
}
// 将十进制转换为任意进制，主要用到的是短除法，也就是 10 % m -> 10 / m...注意字符的转换... 
string d2any(int d, int m) {
	string res = "";
	int temp;
	while (d) {
		temp = d % m;
		if (temp > 9) temp = 'A' + temp - 10;
		else temp += '0';
		res += (char)temp;
		d /= m;
	}
	int l = 0, r = res.size() - 1;
	// 最后得到的答案是倒着的，所以要转换回来... 
	while (l < r) swap(res[l++], res[r--]);
	return res;
}
int main() {
	int n, m;
	string str;
	cin >> n >> str >> m;
	// 把A进制转为10进制，再把10进制转为B进制 
	cout << d2any(any2d(str, n), m);
	return 0;
}
