#include <iostream>
using namespace std;
// �Ȳ����е���͹�ʽ
// ��2 4 6 8 10�������У�d=2���ɴ˿ɵ�sn = n*(n + 1)/2��an = a1 + (n-1)*d 
int dcsl() {
	int n = 10;
	int arr[n];
	for (int i = 1; i <= n; i++) arr[i - 1] = i;
	// int d = arr[1] - arr[0];
	// int a10 = arr[0] + (n - 1) * d;
	int sn = (n * (n + 1)) / 2;
	return sn;
} 
// ƽ���͹�ʽ
// ��1^2 + 2^2 + 3^2 + 4^2�������У�������͹�ʽΪn*(n + 1)*(2*n + 1) / 6 
int pfh(int n) {
	return (n*(n + 1)*(2*n + 1)) / 6;
}
// �����͹�ʽ
// ��1^3 + 2^3 + 3^3 + 4^3�������У�������͹�ʽΪn^2(n + 1)^2 / 4
int lfh(int n) {
	return ((n*n)*((n + 1)*(n + 1))) / 4;
}
// �ȱ����е���͹�ʽ
// ��1, 2, 4, 8..�������͵�����Ϊ�ȱ����У�������q=2���ȱ����е���͹�ʽ��(a1*(1 - q^n)) / 1-q 
int dbsl(int a1, int q, int n) {
	int qn = q;
	for (int i = 1; i < n; i++) qn *= q;
	return (a1*(1 - qn)) / (1-q); 
}
// ���ͼ�������͹�ʽ
// ����1/1+1/2+1/3+��+1/n+���ļ�����Ϊ���ͼ�����ֻ���������ֵ����δ�ҵ���ʽ 
int main() {
	cout << dbsl(1, 2, 3);
	return 0;
}
