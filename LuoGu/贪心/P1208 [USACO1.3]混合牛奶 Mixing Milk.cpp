#include <iostream>
#include <algorithm>
using namespace std;

// ��֪��������ǲ��ǲ��ֱ������⣬����������ղ�����������
// �ƺ�����ȫѡ�����ǿ���ѡһ����

// �ؼ���Ҫ��ǰ�۸����� 

struct elements {
	int m, w, tot;
	elements(int m1 = 0, int w1 = 0, int t1 = 0) {
		m = m1, w = w1, tot = t1;
	}
	bool operator<(const elements& e) {
		// ���۸��� 
		return m < e.m;
	}
};
elements *e;
int main() {
	int t, n;
	int result = 0;
	cin >> t >> n;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].m >> e[i].w;
		e[i].tot = e[i].m * e[i].w;
	}
	sort(e, e + n);
	for (int i = 0; i < n; i++) {
		// cout << e[i].m << ' ' << e[i].w << ' ' << e[i].tot << endl;
		// ȫ��װ���� 
		if (t >= e[i].w) {
			result += e[i].tot;
			t -= e[i].w;
		} else {
			// ֻ��װ�²��֣���ʣ�µĲ���*��ǰţ�̵ļ۸� 
			result += t * e[i].m; 
			break;
		}
	}
	cout << result;
	delete[] e;
	return 0;
}
