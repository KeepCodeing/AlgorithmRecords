#include <iostream>
using namespace std;
int main() {
	// ��Stack�ﴴ������ 
	int arr1[3];
	
	// ��̬��Stack�ﴴ�����飬�ھɱ������лᱨ��
	// ʹ�����ַ������������޷�������г�ʼ����
	// ��Ҫ�Ƿ�ֹ�����Խ�� 
	int n;
	cin >> n;
	int arr2[n];
	
	// ��heap�д������飬ʹ�����ַ�������������
	// ��ʹ�����Ҫ����ɾ����C������new�൱��malloc) 
	int *arr3 = new int[n];
	delete[] arr3; 
	
	// ��heap�д�����ά���飨C:int **arr = (int**)malloc(n * sizeof(int*)) 
	int **arr4 = new int*[n];
	for (int i = 0; i < n; i++) arr4[i] = new int[n];
	return 0;
}
