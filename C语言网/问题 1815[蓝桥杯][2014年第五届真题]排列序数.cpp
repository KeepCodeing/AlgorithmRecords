#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	string temp = str;
	sort(str.begin(), str.end());
	int cnt = 1;
	// �ƺ���ʵ����next_permutation()��������������У�����Ҫ����
	// ������Ϊ��������ʵ���У������±��1��ʼ�����ڶ������� 
	if (str == temp) cout << 0;
	while (next_permutation(str.begin(), str.end())) {
		if (str == temp) {
			cout << cnt;
			break;
		}
		cnt++;
	};
	return 0;
}
