#include <iostream>
#include <cstdio>
using namespace std;

// ������ϰ�ڶ��������Ǹ����01������ģ�� 
// ���̣���ʵ����ȫ��������Ŀû˵һ�������������... 

const int N = 1e5;
int f[N];
int main() {
	int n, T, v, w;
	scanf("%d%d", &n, &T);
	while (T--) {
		scanf("%d%d", &v, &w);
		for (int i = w; i <= n; i++) f[i] = max(f[i], f[i - w] + v);
	}
	printf("%d", f[n]);
	return 0;
} 
