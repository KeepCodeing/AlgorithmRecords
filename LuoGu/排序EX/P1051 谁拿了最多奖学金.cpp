#include <iostream>
#include <algorithm>
using namespace std;

// �ṹ��+����ģ������� 
struct students {
	// ���� 
	string name;
	// ��ǳ��ִ��� 
	int id;
	// ��ĩ�ɼ����༶����ɼ� 
	int qm, bjpy;
	// �ɲ�������ʡ�ݷ� 
	char gb, xb;
	// ������ 
	int lw;
	// �ܽ��� 
	int totMoney;
	students(string s = "", int i = 0, int q = 0, 
	int b = 0, char g = ' ', char x = ' ', int l = 0) {
		name = s, id = i, qm = q, bjpy = b, g = gb,
		xb = x, lw = l;
	}
	bool operator<(const students& s) {
		if (s.totMoney != totMoney) return s.totMoney < totMoney;
		// ����֮ǰ��˳��д���� 
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
	// ����Ѱ༶������ж�д������ĩ�ɼ����������
	// ����bug 
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
		// C������׹���ˣ���֪���ǲ���̫��û�� 
		// scanf("%s %d %d %c %c %d", &s[i].name, &s[i].qm, &s[i].bjpy, &s[i].gb, &s[i].xb, &s[i].lw);
		s[i].id = i, s[i].totMoney = totMoney(s[i]);
		studentTotMoney += s[i].totMoney;
		// ���ﳢ�Բ�����ֱ�Ӽ�¼һ�����ֵ�����������У���Ϊ�ṹ�岻��ֱ�Ӹ�ֵ���ϻ��� 
	}
	sort(s, s + n);
	cout << s[0].name << endl << s[0].totMoney << endl << studentTotMoney;
	delete[] s;
	return 0;
}
