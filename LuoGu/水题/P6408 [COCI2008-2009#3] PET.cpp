#include <iostream>
using namespace std;

// ˮ��ڶ���..�þ�û�н����ˣ���ʵ������������... 

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
