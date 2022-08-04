#include <iostream>
using namespace std;
// 给定一个数组，如{2, 3, 7, 5, 4, 6}，返回4，因为只有{7, 5, 4, 6}需要排序
// 要求时间复杂度为O(n)
// 思路：如果将数组看成一段折线图，如果是一个有序的数组其折线一定是向上或者向下的
// 而如果是个部分无序的数组，中间必然会有曲折，而最高点右侧的区间就说明这个区间没有
// 排序，反正，在最低点左区间的数也可以看出未排序，所以在遍历数组的同时更新最高点的值
// 和最低点的值，并记录下它们的下标，在这个区间内的数就是要排序的数 
const int LEN = 6;
int checkArr(int arr[]) {
	int arrMax, arrMin, maxIndex = 0, minIndex = 0;
	arrMax = arr[0], arrMin = arr[LEN - 1];
	for (int i = 0; i < LEN; i++) {
		if (arr[i] < arrMax) maxIndex = i;
		if (arr[i] > minIndex) minIndex = i;
		if (arr[i] > arrMax) arrMax = arr[i];
		if (arr[i] < arrMin) arrMin = arr[i];
	}
	return maxIndex - minIndex;
}  
int main() {
	int arr[LEN] = {2, 3, 7, 5, 4, 6};
	// 2, 3, 7, 5, 4, 6
	// 2, 3, 4, 5, 6, 7
	cout << checkArr(arr) << endl;
	return 0;
}
