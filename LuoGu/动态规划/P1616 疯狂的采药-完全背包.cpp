#include <iostream>
using namespace std;

// ��ȫ�����ƺ�Ҳ����01����ģ�壬ֻ�����ѵ�������ĳ���˳����� 

struct elements {
	int t, v;
	elements(int t1 = 0, int v1 = 0) {
		t = t1, v = v1;
	}
};
// ��ռ�����̫С��RE�� 
// T�ķ�Χ�� 100000...

// �������ý�ռ�ĸ����Ǳ����ݻ�����Ϊ���Ž�
// �ǵ�T��Ԫ��.. 
int f[100005];
int main() {
	int t, n;
	cin >> t >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].t >> e[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j >= e[i].t) {
				f[j] = max(f[j], f[j - e[i].t] + e[i].v);
			}
		}
	}
	cout << f[t];
	delete[] e;
	return 0;
}
