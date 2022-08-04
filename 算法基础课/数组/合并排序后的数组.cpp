#include <iostream>
using namespace std;
// 给出两个数组A和B，假定它们都已经被排序了且A有足够空间存放B的元素，
// 试将B合并到A中 
// 思路：利用归并排序的思想即可解决 
void mergeArray(int A[], int B[], int Alen, int Blen, int L) {
	int index = 0;
	int *temp = new int[L];
	int a_i = 0, b_i = 0;
	// 这里之前写成了index小于，错误 
	while (a_i < Alen && b_i < Blen) temp[index++] = A[a_i] <= B[b_i] ? A[a_i++] : B[b_i++];
	
	while (a_i < Alen) temp[index++] = A[a_i++];
	while (b_i < Blen) temp[index++] = B[b_i++];
	
	for (int i = 0; i < index; i++) A[i] = temp[i];
}
int main() {
	int A[7] = {1, 2, 3, 9};
	int B[3] = {2, 3, 4};
	mergeArray(A, B, 4, 3, 7);
	for (int i = 0; i < 7; i++) cout << A[i] << ' ';
	
	return 0;
}
