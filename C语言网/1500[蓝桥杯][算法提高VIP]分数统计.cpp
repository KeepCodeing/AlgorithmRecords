#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �������ø�map֮��Ķ��������ݵģ����ǿ������ṹ������

struct stu {
	vector<int > scores;
	int cnt;
	// �о�û��Ҫ���򣬱���һ��ȥ�Ҿ��� 
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
		// ����� 
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
		// �����������ǰ����������+1������������� 
		vec[index].scores.push_back(score), vec[index].cnt++, maxCnt = max(maxCnt, vec[index].cnt); 
	} 
	// ɨһ�飬��ȻҲ����ֱ���������¼����±꣬��������
	// �Ƚ��鷳
	// ���������������֪�������ܲ��ܱ������... 
	for (int i = 1; i <= 5; i++) {
		cout << vec[i].cnt;
		if (i != 5) cout << ' ';
	} 
	for (int i = 1; i <= 5; i++) {
		if (vec[i].cnt == maxCnt) {
			// ���
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
