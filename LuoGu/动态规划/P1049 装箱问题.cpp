#include <iostream>
using namespace std;

// Ҳ��01����������û�м�ֵ��������֮ǰд���ƺ��е�Сbug 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};
int f[50000];
int main() {
	int s, n;
	cin >> s >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w;
		e[i].v = e[i].w;
	}
	for (int i = 1; i <= n; i++) {
		// bug�������j>=0�ᵼ��һ����Ʒ�ظ���ӣ�����������û�������� 
		for (int j = s; j >= e[i].w; j--) {
			if (j >= e[i].w) {
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	// Ҫ�����ʣ��ռ� 
	cout << s - f[s];
	delete[] e;
	return 0;
}
