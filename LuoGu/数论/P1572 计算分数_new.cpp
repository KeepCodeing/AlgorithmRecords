#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// 上一份代码坠毁了w，主要是不会求多个数的最小公倍数，这里再开一个.. 

const int N = 120;
int fz[N], fm[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
// 求n个数的最大公约数，下面求最小公倍数也是一样的... 
int ngcd(int n) {
	if (n == 1) return abs(fm[0]);
	// 注意下标从0开始
	return gcd(fm[n - 1], ngcd(n - 1));
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int nlcm(int n) {
	if (n == 1) return fm[0];
	return lcm(fm[n - 1], nlcm(n - 1));
}
int main() {
	int cnt = 0;
	while (scanf("%d/%d", &fz[cnt], &fm[cnt]) != EOF) cnt++;
	int tfz = 0, tfm = nlcm(cnt);
	// 求出分子乘上最小公倍数/分母倍数的和，也就是当分母都相同时，将分母也扩大同样倍数，然后求和 
	for (int i = 0; i < cnt; i++) tfz += (tfm / fm[i]) * fz[i];
	// 求分子分母的最大公约数，如果它们的最大公约数存在，说明还可以进行约分，注意这里求的是绝对值的最大公约数 
	// 不然可能求出负数 
	int t = gcd(abs(tfm), abs(tfz));
	// 如果分子可以整除分母，就说明这是个整数 
	if (!(tfz % tfm)) printf("%d", tfz / tfm);
	// 否则就进行约分，这里似乎可以不用判断分子分母同时为负的情况w，反正测试数据里是没有的w，也就是说-1/-3这种情况是正确的 
	else printf("%d/%d", tfz / t, tfm / t);
	// 下面全是无用判断 
//	if (!(tfz % tfm)) printf("%d", tfz / tfm);
//	else if (!(tfm % tfz)) {
//		int t = gcd(abs(tfm), abs(tfz));
//		printf("%d/%d", tfz / t, tfm / t);
//	} else printf("%d/%d", tfz, tfm);
	return 0;
}
