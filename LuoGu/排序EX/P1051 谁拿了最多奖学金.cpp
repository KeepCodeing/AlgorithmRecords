#include <iostream>
#include <algorithm>
using namespace std;

// 结构体+排序，模拟就完了 
struct students {
	// 名字 
	string name;
	// 标记出现次数 
	int id;
	// 期末成绩，班级评议成绩 
	int qm, bjpy;
	// 干部，西部省份否 
	char gb, xb;
	// 论文数 
	int lw;
	// 总奖金 
	int totMoney;
	students(string s = "", int i = 0, int q = 0, 
	int b = 0, char g = ' ', char x = ' ', int l = 0) {
		name = s, id = i, qm = q, bjpy = b, g = gb,
		xb = x, lw = l;
	}
	bool operator<(const students& s) {
		if (s.totMoney != totMoney) return s.totMoney < totMoney;
		// 这里之前把顺序写反了 
		return s.id > id;
	}
};
students *s;
long totMoney(students s) {
	long r = 0;
	if (s.qm > 80 && s.lw >= 1) r += 8000;
	if (s.qm > 85 && s.bjpy > 80) r += 4000;
	if (s.qm > 90) r += 2000;
	if (s.qm > 85 && s.xb == 'Y') r += 1000;
	// 这里把班级评议的判断写成了期末成绩，结果排了
	// 半天bug 
	if (s.bjpy > 80 && s.gb == 'Y') r += 850;
	return r;
}
int main() {
	int n;
	cin >> n;
	s = new students[n];
	long studentTotMoney = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].qm >> s[i].bjpy >> s[i].gb >> s[i].xb >> s[i].lw;
		// C的输入坠毁了，不知道是不是太久没用 
		// scanf("%s %d %d %c %c %d", &s[i].name, &s[i].qm, &s[i].bjpy, &s[i].gb, &s[i].xb, &s[i].lw);
		s[i].id = i, s[i].totMoney = totMoney(s[i]);
		studentTotMoney += s[i].totMoney;
		// 这里尝试不排序直接记录一个最大值，不过不可行，因为结构体不能直接赋值（废话） 
	}
	sort(s, s + n);
	cout << s[0].name << endl << s[0].totMoney << endl << studentTotMoney;
	delete[] s;
	return 0;
}
