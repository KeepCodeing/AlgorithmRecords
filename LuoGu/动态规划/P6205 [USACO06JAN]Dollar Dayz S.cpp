#include <iostream>
using namespace std;

// ��ȫ�����󷽰������������ﻹҪ�߾��� 

const int N = 1010, M = 110;
int f[N];
int main() {
	int n, k;
	cin >> n >> k;
	f[0] = 1;
	// ���Ӷ��Ǵ���..
	// ��Ʒ�������ж�����Ǯ�������ݻ���Ҫ������Ǯ 
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			f[j] += f[j - i];
		}
	}
	cout << f[n];
	return 0;
}
