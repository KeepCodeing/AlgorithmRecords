#include <iostream>
#define endl '\n'
using namespace std;

// �����㷨�Ǵ�1~n��ÿ�����������ӣ�Ȼ��ͳ��Ҫ�����������ӵĸ�������Ȼ�������Ӷ�O(n)����n = 10^18ʱЧ�����Խ���
// �������һ��O(logn)���㷨����������������n!��ĩβ�м���0��ֻҪ�ж��м���������5����

int cal(int n, int p) {
	if (n < p) return 0;
	return n / p + cal(n / p, p);
} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout << cal(100, 5);
	return 0;
}
