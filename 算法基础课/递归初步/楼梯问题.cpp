#include <iostream>
using namespace std;
// ����С��Ҫ��n��̨�ף���ÿ�ο�����һ����������������������С��һ���ж�����
// ��ʽ����̨��

// �����������ϵ���n��̨����Ҫf(n)������Ҫ�����f(n)ֻ��Ҫ�����f(n-1),f(n-2),f(n-3)
// ���Եݹ�ʽ����
int f(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return f(n-1) + f(n - 2) + f(n - 3);
} 
int main() {
	cout << f(4) << endl;
	return 0;
}
