#include <iostream>
using namespace std;

// 看了半天题目，题目意思就是判断下是否是偶数.. 
// 然后坠毁了，又看了遍题目发现其要求的是判断当前这个数能不能被偶数组成，而不是要求两个部分相等... 

int main() {
	bool flag = false;
	int num;
	cin >> num;
	if (num > 2 && !(num % 2)) flag = true;
	cout << (flag ? "YES" : "NO") << endl;  
	// 打表发现确实是偶数才能被分成两半，但是要注意2不能被分成两个偶数的和.. 
//	for (int i = 1; i <= 100; i++) {
//		flag = false;
//		for (int j = 2; j < i; j += 2) {
//			if (!((i - j) % 2)) flag = true;
//		}
//		// num >= 1，故而没有特判... 
//		cout << i << ' ' << (flag ? "YES" : "NO") << endl;
//	}
	return 0;
}
