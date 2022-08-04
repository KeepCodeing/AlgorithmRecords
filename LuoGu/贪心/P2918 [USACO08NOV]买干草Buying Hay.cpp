#include <iostream>
#include <algorithm>
using namespace std;

struct elements {
	int w, m;
	double p;
	elements(int w1 = 0, int m1 = 0, double p1 = .0) {
		w = w1, m = m1, p = p1;
	}
	// ǮԽ��Խ��ǰ����Ų����У����Լ۱������� 
	bool operator<(const elements& e) {
		return p > e.p;
	}
};
elements *e;
int main() {
	int n, h;
	int temp;
	cin >> n >> h;
	e = new elements[n];
	for (int i = 0; i < n; i++) {
		cin >> e[i].w >> e[i].m;
		// ������ղ��ֱ����Ľⷨ������ɽ⣿
		// ����һ���Լ۱� 
		e[i].p = e[i].w * 1.0 / e[i].m; 
	}
	sort(e, e + n);
	// ̰�Ĳ��ԣ���ѡ�Լ۱ȸߵģ���Ϊѡ���꣬����
	// ����һֱѡ���������ﲻ�ܷ���ѡ��Ҳ����˵
	// �����ѡ��������ȵĸɲ�
	int ans = 0;
	int index = 0;
	while(true) {
		temp = e[index].w;
		if (h == 0) {
			break;
		} else if (h > 0) {
			h -= temp;
			ans += e[index].m;
		} else {
			h += temp;
			ans -= e[index].m;
			index++;
		}
	} 
	cout << ans;
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << e[i].w << ' ' << e[i].m << ' ' << e[i].p << endl;
//
//	}
	return 0;
}
