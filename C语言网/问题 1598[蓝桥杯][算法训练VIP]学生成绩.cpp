#include <iostream>
#include <algorithm>
using namespace std;

/*
除了sort以外另外的两种排序方法，其中stable_sort()适用于这个题目 
stable_sort()是对给定区间的元素进行稳定排序，如果两个元素相等，那么排序完成后两个元素的相对位置保持不变，
partial_sort()是对给定区间的元素进行部分排序。默认的顺序是由小到大进行排序。
*/

struct student {
	string name, gender;
	int age, score, id;
	student() {};
	student(string name, string gender, int age, int score) : name(name), gender(gender), age(age), score(score) {};
	bool operator<(const student& s) {
		// 解决顺序问题的方法：记录一个id，排序的时候如果得分相同就按id排序 
		if (score != s.score) return score < s.score;
		return id < s.id;
	}
};
student ss[1010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ss[i].name >> ss[i].gender >> ss[i].age >> ss[i].score, ss[i].id = i;
	sort(ss, ss + n);
	for (int i = 0; i < n; i++) cout << ss[i].name << ' ' << ss[i].gender << ' ' << ss[i].age << ' ' << ss[i].score << endl;
	return 0;
}
