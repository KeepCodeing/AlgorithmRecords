//#include <iostream>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int n;
//	cin >> n;
//	while (n--) {
//		string name;
//		int score, old;
//		cin >> name >> old >> score;
//		cout << name << ' ' << old + 1 << ' ';
//		score += score * 0.2;
//		if (score >= 600) score = 600;
//		cout << score << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
struct shenben {
	string name;
	int old, score;
	shenben(string name, int old, int score) : name(name), old(old), score(score) {};
}; 
vector<shenben > modmodmod;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string name;
		int old, score;
		cin >> name >> old >> score;
		modmodmod.push_back(shenben(name, old + 1, score + score * 0.2 >= 600 ? 600 : score + score * 0.2)); 
	}
	for (int i = 0; i < modmodmod.size(); i++) {
		cout << modmodmod[i].name << ' ' << modmodmod[i].old << ' ' << modmodmod[i].score << endl;
	}
	return 0;
}
