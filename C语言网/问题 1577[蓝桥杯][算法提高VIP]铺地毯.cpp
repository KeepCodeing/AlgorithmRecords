#include <iostream>
using namespace std;
struct dt {
	int x, y, a, b, id;
	dt() {}
	dt(int x, int y, int id) : x(x), y(y), id(id) {};
};
// �����ʹ��㴿ģ��ģ����IDE���ά���鿪���ˣ�OJ��ȴRE��
// �����������������������⣬���Կ����ø��ṹ��ģ�� 
dt d[10010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i].x >> d[i].y >> d[i].a >> d[i].b;
		d[i].id = i + 1;
	}
	int x, y;
	cin >> x >> y;
	// ���ű�����Խ���̵ĵ�̺Խ���ϲ� 
	for (int i = n - 1; i >= 0; i--) {
		// ֻ��Ҫ�ж������������ǲ����������̺�ĳ��������� 
		if (x >= d[i].x && x <= d[i].x + d[i].a && y >= d[i].y && y <= d[i].y + d[i].b) {
			cout << d[i].id;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
