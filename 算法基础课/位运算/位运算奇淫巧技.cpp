#include <iostream>
using namespace std;
// 位运算判断奇数偶数
// 原理：整数中奇数的最低位总为1，偶数的最低位总为0,也就是num & 1 == 1则为奇数，相反为偶数 
bool checkNum(int num) {
	return num & 1;
}
int main() {
	int num;
	cin >> num;
	cout << checkNum(num) << endl;
	return 0;
}
