#include <iostream>
#include <algorithm>
using namespace std;

// ������map��д��ö������...

int n, k;
struct student {
	int score;
	string name;
	bool operator<(const student& s) {
		return score > s.score;
	}
}; 
student s[110];
// ����ѧ���ɼ� 
void insertScore(string name, int score) {
	for (int i = 0; i < n; i++) {
		if (s[i].name == name) {
			s[i].score += score;
			break;
		}
	}
}
// �ҵ��������� 
int findDada(int score) {
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		// �ɼ���ͬ��������ֻ�Ǵ������� 
		if (s[i].score == score && s[i].name != "DaDa") continue;
		// ��Ϊcnt�Ǵ�1��ʼ�ģ�����Ҫ��ǰbreak 
		if (s[i].name == "DaDa") break;
		cnt++;
	}
	return cnt;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name;
		s[i].score = 0;
	}
	int dScore = 0;
	cin >> k;
	while (k--) {
		for (int i = 0; i < n; i++) {
			int score;
			string name;
			cin >> score >> name;
			// ��¼���ķ������������ 
			if (name == "DaDa") dScore += score;
			insertScore(name, score);
		}
		sort(s, s + n);
		cout << findDada(dScore) << endl;
	}
	return 0;
}
