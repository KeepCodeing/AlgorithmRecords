#include <iostream>
using namespace std;

// �����������������01��������һά�����Ż���д�� 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};
int f[50000];
int main() {
	int n, v;
	cin >> n >> v;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w >> e[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 0; j--) {
			if (j >= e[i].w) {
				// ����֮ǰд����f[i-1]�����Ƕ�ά����δ�Ż���д��...
				// һά�����Ż�д��ֻ���ĵ�ǰ�ܷ������Ž� 
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	// һά�����Ż�������Ž��ɱ���������� 
	cout << f[v];
	delete[] e;
	return 0;
}
