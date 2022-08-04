#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 本来想用个map之类的东西存数据的，但是看起来结构体足矣

struct stu {
	vector<int > scores;
	int cnt;
	// 感觉没必要排序，遍历一遍去找就行 
}; 
vector<stu > vec;
bool cmp(int s1, const int s2) {
	return s1 > s2;
}
int main() {
	vec.resize(10);
	int n, score;
	int index;
	int maxCnt = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		// 分五等 
		if (score >= 90 && score <= 100) {
			index = 1;
		} else if (score >= 80 && score <= 89) {
			index = 2;
		} else if (score >= 70 && score <= 79) {
			index = 3;
		} else if (score >= 60 && score <= 69) {
			index = 4;
		} else {
			index = 5;
		}
		// 加入分数，当前分数层人数+1，更新最大人数 
		vec[index].scores.push_back(score), vec[index].cnt++, maxCnt = max(maxCnt, vec[index].cnt); 
	} 
	// 扫一遍，当然也可以直接在上面记录最大下标，不过可能
	// 比较麻烦
	// 先输出下人数，不知道这样能不能比排序快... 
	for (int i = 1; i <= 5; i++) {
		cout << vec[i].cnt;
		if (i != 5) cout << ' ';
	} 
	for (int i = 1; i <= 5; i++) {
		if (vec[i].cnt == maxCnt) {
			// 输出
			cout << endl << maxCnt << endl;
			sort(vec[i].scores.begin(), vec[i].scores.end(), cmp);
			int vLen = vec[i].scores.size();
			for (int j = 0; j < vLen; j++) {
				cout << vec[i].scores[j];
				if (j != vLen - 1) cout << ' ';
			}
			break;
		}
	} 
	return 0;
}
