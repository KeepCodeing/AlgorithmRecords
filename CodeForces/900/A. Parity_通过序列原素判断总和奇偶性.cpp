#include <iostream>
using namespace std;

// 枚举几个数字，可以发现奇数+奇数=偶数，偶数+奇数=奇数，偶数+偶数=偶数，而这个题
// 给出的k的次方非常的大，如果直接相加然后判断结果奇偶绝对会溢出。后来想了下，判断
// 单项的奇偶也不能通过把a的k次方算出来的方案来，因为这样极限数据溢出更快w。那么问题
// 就又多了个，判断奇偶的k次方的奇偶性，还有就是b可能是奇数也可能是偶数，而后面a的k次方
// 乘上它又会有什么结果，这也是个问题。
// 下面写个暴力，枚举下奇数的平方和偶数的平方的情况... 
// 例子3：其10次方都是奇数
// 例子2：其10次方都是奇数
// 那么有了这两个例子就能简单的认为奇数的k次方始终是奇数，偶数的k次方始终是偶数了，也就是说次方对奇偶性没有影响，接下来可以
// 讨论下奇数*偶数的奇偶性了（上面已经说明奇偶性相同的数相乘得到的数奇偶不变了）... 
// 简单的想了几个数得到了奇数*偶数=偶数的结论，接下来还要判断下a为0或1的情况（b>=2)
// 0的任意次方还是0，1的任意次方也还是1，这样就能得到：当a==0时，该项对整个序列的奇偶性不做贡献，
// 而当a==1时，就变成了上面提到的三种相加的情况了... 

// 10 + 
unsigned long long res = 0;
int main() {
	int b, k, a;
	cin >> b >> k;
	long long temp = 1;
	string now = "", pre = "";
	// b是偶数否 
	bool b_even = !(b % 2);
	while (k--) {
		cin >> a;
		if (k == 0) {
			if (now == "odd" && a % 2) now = "even";
			else if (now == "even" && a % 2) now = "odd";
			continue;
		}
		// b是偶数，那么其乘奇数会得到偶数
		if (b_even) {
			// 如果当前元素a是奇数 
			if (a == 0) continue;
			if (a % 2) now = "even";
			else now = "even";
//			if (a == 1) 
			// 判断之前加起来的数的奇偶性，奇数加偶数得奇数，否则还是偶数... 
			if (now == "odd" && pre == "even") now = "odd";
			else now = "even";
		} else {
			// b是奇数，那么它乘上偶数就会变成偶数
			if (!(a % 2)) now = "even";
			else now = "odd";
			// 同样判断下奇偶性，奇数+奇数得偶数，奇数加偶数得奇数 
			if (now == "odd" && pre == "odd") now = "even";
			else now = "odd";
		}
//		cout << now << endl;
		// 更新序列当前的奇偶性 
		pre = now;
	}
	cout << now << endl;
	return 0;
}
//		cin >> a;
//		res += a * b;
//		temp = 1;
//		cin >> a;
//		for (int i = 0; i < k; i++) temp *= b;		
//		res += a * temp;
//		cout << a * temp << endl;
//	while (k--) {
//
//	}
//	cout << res << endl;
//	cout << res % 2 << endl;;
