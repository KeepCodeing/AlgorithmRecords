#include <iostream>
using namespace std;
// ˼·���Ӻ���ǰ�Ա��������飬Ԫ�ش�Ŀ��󣬲����ø������С����������һ������
// ��С�����Աȣ�ֱ��ĳ�������Ԫ�ر��Ա�����ˣ���ʱ������и�����û�б��Ա����
// ��ô������ĸ�����Ǹ����飬��ʱֻ��Ҫ������Ԫ�ؼ��� 
// m��A�����һ��Ԫ�ص��±꣬n��B�����һ��Ԫ�ص��±� 
void mergeSortedArray(int A[], int m, int B[], int n) {
	 
	int index = n + m;
	while (m > 0 && n > 0) {
		// �Ӻ���ǰ�Ƚ���������������Ԫ�صĴ�С 
		if (A[m - 1] > B[n - 1]) {
			// ���A��Ԫ�ش���ôA��Ԫ�ؾ͸������෴B��Ԫ�ظ����� 
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
