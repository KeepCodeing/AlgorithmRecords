#include <iostream>
#include <vector>
using namespace std;
struct studentScore {
	int gradeSocre;
	int extraScore;
	int id;
	float collScore;
	studentScore(int gs = 0, int ex = 0, float cl = .0, int i = 0) {
		gradeSocre = gs, extraScore = ex, collScore = cl, id = i;
	}
	int getGES() {
		return gradeSocre + extraScore;
	}
};
int main() {
	int n;
	vector<studentScore > s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		studentScore t;
		cin >> t.id >> t.gradeSocre >> t.extraScore;
		t.collScore = .7 * t.gradeSocre + .3 * t.extraScore;
		s.push_back(t); 
	} 
	int sSize = s.size();
	for (int i = 0; i < sSize; i++) {
		// ��С�ڵ���˼û���������С��Ӧ�þ��Ǵ��ڵ���˼...���Ǵ��ڵ���... 
		// �ݣ���Ŀ�ָ��ˣ���С�ھ��Ǵ��ڵ��ڵ���˼... 
		if (s[i].getGES() > 140 && s[i].collScore > 80) cout << "Excellent";
		else cout << "Not excellent";
		if (i != sSize - 1) cout << endl;
	}
	return 0;
}
