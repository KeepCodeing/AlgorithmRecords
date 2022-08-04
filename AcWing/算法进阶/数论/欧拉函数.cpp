#include <iostream>
#define endl '\n'
using namespace std;

// 欧拉函数与互质：
// 互质就是指gcd(a, b) == 1, 而欧拉函数的作用就是求1~n中与n互质的数有多少个...它的写法可以基于线性筛或者试除法，
// 公式为phi(n) = n * (pi - 1) / pi（pi为n的质因子, i~n），注意这里有个技巧，那就是把这个式子改造成n / pi * (pi - 1)，
// 这样做的原因是因为先进行乘法运算可能产生溢出，先除后乘则可以保证不会出现溢出... 

// 性质1：1~n中与n互质的数的和为n * phi(n) / 2
// 性质2：如果a,b互质，那么phi(ab) = phi(a) * phi(b)

// 欧拉定理的推论：如果a与n互质，那么a^b % n == a^(b % phi(n)) % n，也就是题目让我们求a^b然后对n取模时，当a, n互质时可以
// 先将a的指数b对phi(n)求模，再对n求模...（这种情况适用于答案对某个质数取模，它可以将计算范围缩小） 
// 用法：对于a + b, a - b, a * b这种式子可以直接先让a, b对n求模，而a^b这种乘方公式可以先转换为(a % n)^(b % phi(n))，
// 也就是底数和指数分别求模再进行乘方，这样就能一定程度保证不会溢出... 

int phi(int n) {
	int ans = n;
	for (int i = 2; i <= n / i; i++) {
		// 注意这里的写法，我们只取任意一个质因子一次，因此先判断i是不是一个质因子，再到下面进行整除 
		if (!(n % i)) {
			ans = ans / i * (i - 1);
			while (!(n % i)) n /= i;
		}
	}
	if (n > 1) ans = ans / n * (n - 1);
	return ans; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);	
	int n;
	cin >> n;
	cout << phi(n) << endl;
	return 0;
}
