#include <iostream>
using namespace std;

// ���������İ���... 

const int N = 20;
typedef long long LL;
LL f[N];
int main() {
	int n;
	cin >> n;
	f[0] = 1;
	// ����ʽ����ǰ��������=��һ����������*(�ı��ĵ�ǰλ�� - 2) / ��ǰλ�� + 1 
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * (i * 4 - 2) / (i + 1);
	cout << f[n];
	return 0;
}
