#include <iostream>
using namespace std;

// ��֪���ǲ�����ȫ��������дд���о�Ҳ����̰�Ľ� 
// ������������ȫ��������ʵ��д��ʱ��Ҳ�о������
// �ͱ�����һ��������Ҫ�������װ���ļ�ֵ����Ʒ��
// �����Ҫ�������С���� 

struct elements {
	int w, m;
	elements(int w1 = 0, int m1 = 0) {
		w = w1, m = m1;
	}
};
elements *e;
int f[50001];
int main() {
	int n, h;
	cin >> n >> h;
	e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w >> e[i].m;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= e[i].w; j++) {
			f[j] = max(f[j], f[j - e[i].w] + e[i].m);
		}
	}
	cout << f[n];
	return 0;
}
