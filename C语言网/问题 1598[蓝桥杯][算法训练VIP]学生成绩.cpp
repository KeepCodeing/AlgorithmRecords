#include <iostream>
#include <algorithm>
using namespace std;

/*
����sort����������������򷽷�������stable_sort()�����������Ŀ 
stable_sort()�ǶԸ��������Ԫ�ؽ����ȶ������������Ԫ����ȣ���ô������ɺ�����Ԫ�ص����λ�ñ��ֲ��䣬
partial_sort()�ǶԸ��������Ԫ�ؽ��в�������Ĭ�ϵ�˳������С�����������
*/

struct student {
	string name, gender;
	int age, score, id;
	student() {};
	student(string name, string gender, int age, int score) : name(name), gender(gender), age(age), score(score) {};
	bool operator<(const student& s) {
		// ���˳������ķ�������¼һ��id�������ʱ������÷���ͬ�Ͱ�id���� 
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
