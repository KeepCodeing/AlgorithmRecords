#include <iostream>
using namespace std;

// ��������Ҳ�Ǹ�01�������⣬ֻ������û��value���ѡ���ˣ����Ǹ��������Ľ��ͣ�������Ȼ����
// �����Ӹ���value������value����Ϊ�ݵ����������������Ҳ����˵��װ�����⣬����û��

int f[50000]; 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};

int main() {
	int w, n;
	cin >> w >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w;
		// �����ֵ����Ϊ������������������01����ģ����
		e[i].v = e[i].w; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = w; j >= 0; j--) {
			if (j >= e[i].w) {
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	cout << f[w];
	delete[] e;
	return 0;
}
