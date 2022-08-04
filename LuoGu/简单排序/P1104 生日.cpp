#include <iostream>
#include <algorithm>
using namespace std;

// Ӧ�þ��������������С������ǰ�� 
// �����������ǣ����ǵ�����Ա� 

struct student {
	string name;
	int id;
	int year, mouth, day;
	student(string n = "", int y = 0, int m = 0, int d = 0, int i = 0) {
		name = n, year = y, mouth = m, day = d, id = i;
	}
	bool operator<(const student& s) {
		if (year != s.year) return year < s.year;
		if (mouth != s.mouth) return mouth < s.mouth;
		if (day != s.day) return day < s.day;
		return id > s.id;
	}
};
student *s;
int main() {
	int n;
	cin >> n;
	s = new student[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].year >> s[i].mouth >> s[i].day;
		s[i].id = i;
	}
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		cout << s[i].name;
		if (i != n - 1) cout << endl;
	}
	return 0;
}
