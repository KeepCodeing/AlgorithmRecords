#include <iostream>
#include <algorithm>
using namespace std;

// senpai sikus!

struct student {
	int id, tot, c, m, e;
	string name;
	student(int i = 0, int tot1 = 0, string n = "") {
		id = i,tot = tot1, name = n;
	}
	bool operator<(const student& s) {
		if (tot != s.tot) return tot > s.tot;
		return id < s.id;
	}
};
student *s;
int main() {
	int n;
	cin >> n;
	s = new student[n];
	int c, m, e;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> c >> m >> e;
		s[i].id = i;
		s[i].c = c, s[i].m = m, s[i].e = e;
		s[i].tot = c + m + e;
	}
	sort(s, s + n);
	cout << s[0].name << ' ' << s[0].c << ' ' << s[0].m << ' ' << s[0].e;
	delete[] s;
	return 0;
} 
