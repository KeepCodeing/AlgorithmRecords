#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 和求质因子的题一样，同样可以用试除法优化 

// n % i == 0绝对为一个约数，而这种情况下 n / i也绝对是一个约数
// 也就是说一个数除以它的约数可以得到这个数的另一个约数，当然可能会相同，所以要判断下除数是不是
// 和约数一样 

vector<int > solve(int n) {
	vector<int > res;
	// 试除法，另外还要判断一种特殊情况，就是当n = i的时候，这是得到的就是1
	for (int i = 1; i <= n / i; i++) {
		if (!(n % i)) {
			// 首先把n的所有约数添加进解集里 
			res.push_back(i); 
			// 再把后半部分可能的约数添加到解集里，但是要判断下i是不是不等于n / i，也就是
			// 1的情况  
			if (i != n / i) res.push_back(n / i); 
		}
	} 
	sort(res.begin(), res.end());
	return res;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		vector<int > res = solve(x);
		for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
		cout << endl;
	} 
	return 0;
}
/*
输入样例
2
6
8

输出样例
1 2 3 6 
1 2 4 8 
*/ 
