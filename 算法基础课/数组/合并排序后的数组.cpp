#include <iostream>
using namespace std;
// ������������A��B���ٶ����Ƕ��Ѿ�����������A���㹻�ռ���B��Ԫ�أ�
// �Խ�B�ϲ���A�� 
// ˼·�����ù鲢�����˼�뼴�ɽ�� 
void mergeArray(int A[], int B[], int Alen, int Blen, int L) {
	int index = 0;
	int *temp = new int[L];
	int a_i = 0, b_i = 0;
	// ����֮ǰд����indexС�ڣ����� 
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
