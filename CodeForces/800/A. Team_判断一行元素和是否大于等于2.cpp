#include <iostream>
using namespace std;

// 题目的意思是三个人中有两个人能确定一个题目的解，那么就可以解决这个问题，最后问
// 一共能解决多少个问题... 

int main() {
	int n, a, b, c, res = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (a + b + c >= 2) res++;
	}
	cout << res << endl;
	return 0;
}
