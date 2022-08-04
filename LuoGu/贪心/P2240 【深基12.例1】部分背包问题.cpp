#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������Ǹ��������⣬��ʵ�����������Էָ�����������ǲ��ֱ����ı�־�����е���̰�����⣬
// ��Ҫ˼·���ǰ��Լ۱������Լ۱�Խ��Խֵ�ü��뱳�����������װ����ȫ����ֵ����Ʒ�ˣ�
// ��ô�Ϳ�����ʣ������*����Ʒ���Լ۱ȣ����ɰѱ������� 

struct elements {
	// ��������ֵ���Լ۱� 
	double w, v, p;
	elements(double w1 = 0, double v1 = 0, double p1 = 0) {
		w = w1, v = v1, p = p1;
	}
	bool operator<(const elements& e) {
		return p > e.p;
	}
};
elements *e;
int main() {
	int n, t;
	double result = 0;
	cin >> n >> t;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].w >> e[i].v;
		// �����Լ۱ȵ��ڼ۸�������� 
		e[i].p = e[i].v / e[i].w;
	} 
	// ��֤�Լ۱�Խ��Խ��ѡ�� 
	sort(e, e + n);
	for (int i = 0; i < n; i++) {
		// ��������ʣ���������Ϳ��Լ���װ�Լ۱ȸߵĶ��� 
		if (t >= e[i].w) {
			result += e[i].v;
			t -= e[i].w;
		} else {
			// ʣ��ռ䲻����װ��������Ʒ��
			// ��ֻװ����
			result += e[i].p * t;
			break;
		}
	}
	delete[] e;
	printf("%.2lf", result);
	return 0;
}
