#include <iostream>
using namespace std;

// �ƺ��ÿ��������ı��ʣ������ı��ʾ��Ǳ��ε�fib����.. 
// Ȼ��������Ǵ��w�����ǵô����֤... 

typedef unsigned long long ULL;
const int N = 60;
ULL f[N];
int main() {
	f[1] =  1, f[2] = 2, f[3] = 3, f[4] = 4;
	for (int i = 5; i < N; i++) f[i] = f[i - 1] + f[i - 3];
	int n;
	while (cin >> n, n) cout << f[n] << endl;
	return 0;
}
