#include <iostream>
#include <cmath>
using namespace std;
struct student {
	int c, m, e;
	int tot;
	string name;
	student(int c1 = 0, int m1 = 0, int e1 = 0, string n = "", int t = 0) {
		c = c1, m = m1, e = e1, name = n, tot = t;
	}
};
student *s;
int main() {
	int n;
	cin >> n;
	s = new student[n];
	for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].c >> s[i].m >> s[i].e, s[i].tot = (s[i].c + s[i].m + s[i].e);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(s[j].c - s[i].c) <= 5 && abs(s[j].m - s[i].m) <= 5 && abs(s[j].e - s[i].e) <= 5 && abs(s[i].tot - s[j].tot) <= 10) {
				cnt++;
				// ��Ŀ˵Ҫ�����ֵ����������������ж��£����Ǹ�������������ֵ������Բ��ã� 
				cout << s[i].name << ' ' << s[j].name << endl;
				// ����ĵط���һ��ѧ�������ж������൱�Ķ���... 
				// break;
			}
		}
	}
//	for (int j = 0; j < cnt; j++) {
//		cout << p[j][0] << ' ' << p[j][1];
//		if (j != cnt - 1) cout << endl;
//	}
	delete[] s;
	return 0;
}
