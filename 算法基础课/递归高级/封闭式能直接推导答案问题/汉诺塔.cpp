#include <iostream>
using namespace std;
// 汉诺塔问题：将n-1个盘子看成一个整体，第n个盘子看成一个整体，
// 一共进行三次操作，将n-1个盘子移到B柱上，再将n盘子移到C柱上
// 最后将n-1个盘子移到C柱上

// 推导可知其一共要移动2^n-1次 
void hnt(char A, char B, char C, int n) {
	if (n <= 1) {
		cout << A << ' ' << B << ' ' << C << endl;
		return;
	}
	hnt(A, B, C, n - 1);
	hnt(A, C, B, 0);
	hnt(B, C, A, n - 1);
}
int main() {
	hnt('A', 'B', 'C', 3);
	return 0;
}
