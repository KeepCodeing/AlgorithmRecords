#include <iostream>
using namespace std;

// ��������ȫ���������Ѵ��ֻ��ö�ٳ�ǰ80���� 

// ����Ҳ���ò���ˣ����ܣ� 

int f[103];
int main() {
	// ���Ĵ�С���Ǳ�����С��ÿ������������
	int n;
	cin >> n;
	fill(f, f + 103, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f[j] += f[j - i];
		}
	}
	cout << f[n];
	return 0;
}
