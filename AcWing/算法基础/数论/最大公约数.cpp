#include <iostream>
using namespace std;

// 辗转相除法：如果a % b大于0，a改为较小值b，将b改为a % b，依次
// 类推直到b为0了，a就是最大公约数 

// 辗转相除法时间复杂度为log(n)，所以效率很高 

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	} 
	return 0;
}
/*
输入样例
2
3 6
4 6

输出样例
3
2
*/
