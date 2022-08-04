#include <iostream>
using namespace std;

// 惯例的思路，先转换成十进制，然后加起来，再转换回去... 
// 草，这个题还要搞高精w，那只能py了w... 

typedef long long LL;
LL any2d(string str, int n) {
	LL res = 0, pf = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] >= 'A' && str[i] <= 'Z') res += (10 + str[i] - 'A') * pf;
		else res += (str[i] - '0') * pf;
		pf *= n;
	}
	return res;
}
void d2any(LL d, int m) {
	string res;
	int temp;
	while (d) {
		temp = d % m;
		// 注意这里的-10，因为类似10之类的模数其实要变成字母是从0,1,2..之类的开始的，所以要减10.. 
		if (temp > 9) temp = 'A' + temp - 10;
		else res += temp + '0';
		d /= m;
	}
	// 其实可以不用返回，直接倒序输出就完事了w... 
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
}
int main() {
	int B;
	string a, b;
	cin >> B >> a >> b;
	d2any(any2d(a, B) + any2d(b, B), B);
	return 0;
}
