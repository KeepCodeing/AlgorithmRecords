#include <iostream>
using namespace std;
int main() {
	// 看了下似乎暴力100%数据光循环就得跑9s了...
	// 这种数据范围下的算法题应该是nlogn左右的复杂度，这种算法有二分，双指针等.. 
//	for (int i = 0; i < 100000; i++) {
//		for (int j = i + 1; j < 100000; j++);
//	}
	// 发现k最多四位，那么可以直接把长度>=当前k的位数的数排除掉，这里使用取模等操作必然很慢，可以先把包含k的区间算出来，那么可以接受的数
	// 就至少包含在k / 10这个区间内..
	// 也就是说问题直接变成了k / 10的区间内有多少个数大于它，然后找下在给定序列里有没有这种数就行了.. 
	return 0;
} 
