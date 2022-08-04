#include <iostream>
#include <algorithm>
using namespace std;

// 不想用map，写个枚举算了...

int n, k;
struct student {
	int score;
	string name;
	bool operator<(const student& s) {
		return score > s.score;
	}
}; 
student s[110];
// 插入学生成绩 
void insertScore(string name, int score) {
	for (int i = 0; i < n; i++) {
		if (s[i].name == name) {
			s[i].score += score;
			break;
		}
	}
}
// 找到达达的排名 
int findDada(int score) {
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		// 成绩相同不计数，只记达达的排名 
		if (s[i].score == score && s[i].name != "DaDa") continue;
		// 因为cnt是从1开始的，所以要提前break 
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
			// 记录达达的分数，方便查找 
			if (name == "DaDa") dScore += score;
			insertScore(name, score);
		}
		sort(s, s + n);
		cout << findDada(dScore) << endl;
	}
	return 0;
}
