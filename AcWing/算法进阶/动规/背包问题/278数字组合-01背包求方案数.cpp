#include <iostream>
using namespace std;

// 01�����󷽰��� 

const int N = 110;
int f[N];
int main() {
	int n, m;
	cin >> n >> m;
	f[0] = 1;
	// 01�����󷽰�������Ʒ�ݻ��������ָ����������ݻ�����Ҫ�յ��� 
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		for (int j = m; j >= v; j--) f[j] += f[j - v];
	}
	cout << f[m] << endl;
	return 0;
}
/*
����������
4 4
1 1 2 2
���������

3
*/
