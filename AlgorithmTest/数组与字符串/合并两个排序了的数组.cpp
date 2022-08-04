#include <iostream>
using namespace std;
// 思路：从后往前对比两个数组，元素大的靠后，并且拿该数组更小的数和另外一个数组
// 较小的数对比，直到某个数组的元素被对比完毕了，这时如果买有个数组没有被对比完毕
// 那么该数组的更大的那个数组，这时只需要向后填充元素即可 
// m是A的最后一个元素的下标，n是B的最后一个元素的下标 
void mergeSortedArray(int A[], int m, int B[], int n) {
	 
	int index = n + m;
	while (m > 0 && n > 0) {
		// 从后往前比较这两个数组的最后元素的大小 
		if (A[m - 1] > B[n - 1]) {
			// 如果A的元素大，那么A的元素就更靠后，相反B的元素更靠后 
			A[--index] = A[--m];
		} else {
			A[--index] = B[--n];
		}
	} 
	while (n > 0) {
		A[--index] = B[--n];
	}
	while (m > 0) {
		A[--index] = A[--m];
	}
}
int main() {
	
	return 0;
}
