#include <iostream>
#include <algorithm>
using namespace std;

// 搞了差不多一下午的电工电子技术，还没搞完，先水水题算了... 

// 屑题目，搞不懂其排序规则，坠毁两次，放弃（ 

struct stu {
	string name;
	int score, age;
	bool operator<(const stu& s) {
		if (score != s.score) return score < s.score;
		if (name != s.name) return name > s.name;
		return age < s.age;
	}
};
stu *student;
int main() {
	int n;
	cin >> n;
	student = new stu[n];
	for (int i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].age >> student[i].score;
	}
	sort(student, student + n);
	for (int i = 0; i < n; i++) {
		cout << student[i].name << ' ' << student[i].age << ' ' << student[i].score;
		if (i != n - 1) cout << endl;
	}
	delete[] student;
	return 0;
}
