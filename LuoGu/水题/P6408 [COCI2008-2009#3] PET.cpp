#include <iostream>
using namespace std;

// 水题第二弹..好久没有进步了，其实不倒车都难了... 

int main() {
	int score, t, maxScore = -1, id = 1;
	for (int i = 1; i <= 5; i++) {
		score = 0;
		for (int j = 0; j < 4; j++) cin >> t, score += t;
		if (score > maxScore) maxScore = score, id = i;
	}
	cout << id << ' ' << maxScore;
	return 0;
}
