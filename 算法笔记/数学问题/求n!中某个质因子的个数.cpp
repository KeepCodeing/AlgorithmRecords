#include <iostream>
#define endl '\n'
using namespace std;

// 朴素算法是从1~n算每个数的质因子，然后统计要求的这个质因子的个数，当然这样复杂度O(n)，在n = 10^18时效率难以接受
// 这里给出一个O(logn)的算法，它还可以用来求n!的末尾有几个0，只要判断有几个质因子5就行

int cal(int n, int p) {
	if (n < p) return 0;
	return n / p + cal(n / p, p);
} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout << cal(100, 5);
	return 0;
}
