#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int > result;
char map[201][201];
int main() {
	char n;
	int cnt = 0;
	int index = 0, line = 0;
	// C++��cin������ܻ��з� 
	while ((n = getchar()) != EOF) {
		cnt++;
		if (n == '\n' && cnt >= line - 1) {
			index = 0;
			line++;
			cout << '=' << cnt << '=';
			cnt = 0;
			continue;
		}
		map[line][index]= n;
		index++;
	}
	cout << line << ' ';
	// �Ե�һ��Ԫ�ز���0�������⴦�� 
	if (map[0][0] == '1') cout << 0 << ' ';
	int cnt_zero = 0, cnt_one = 0;
	for (int i = 0; i < line; i++) {
		for (int n = 0; n < line; n++) {
			if (map[i][n] != '1') {
				cnt_zero++;
				if (cnt_one != 0) {
					cout << cnt_one << ' ';
					cnt_one = 0;
				}
			} else {
				cnt_one++;
				if (cnt_zero != 0) {
					cout << cnt_zero << ' ';
					cnt_zero = 0;
				}
			}
		}
	}
	// ������ͳ�ƽ����������Ϊ���㼴һ�����Ա���һ��ͳ���޷���ѭ������� 
	if (cnt_zero != 0) cout << cnt_zero;
	else cout << cnt_one;
	return 0;
}
