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
				// 题目说要按照字典序排序，所以这里判断下（但是给出的输入就是字典序，所以不用） 
				cout << s[i].name << ' ' << s[j].name << endl;
				// 错误的地方，一个学生可以有多对旗鼓相当的对手... 
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
