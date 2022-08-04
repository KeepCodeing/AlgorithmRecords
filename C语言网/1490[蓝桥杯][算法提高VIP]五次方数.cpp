#include <iostream>

using namespace std;

// 好像是某个18级学长在群里问的题，谔谔 
// 题目居然没给数据范围，坑 
// 果然被坑了，没有0和1... 

// 跑了快2min，确实只有几个数 
int getPow(int n) {
	return n * n * n * n * n;
}
int main() {
//	int t, sumNum = 0;
//	for (int i = 0; i <= 2 * 0x3FFFFFFF; i++) {
//		t = i, sumNum = 0;
//		while (t) {
//			sumNum += getPow(t % 10);
//			t /= 10;
//		}
//		if (sumNum == i) cout << i << endl;
//	}
	cout << 4150 << endl << 4151 << endl <<
			54748 << endl <<
			92727 << endl <<
			93084 << endl <<
			194979;
	return 0;
}
