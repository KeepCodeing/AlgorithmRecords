#include <iostream>
using namespace std;

// �������жϻ������ֵĻ����ϼ��˸��ж�λ���� 

// ��û�����������������-1�����Ҹ�����

int main() {
	int n;
	bool flag = false;
	cin >> n; 
	int sumT, t, tot;
	for (int i = 10000; i <= 999999; i++) {
		t = i, sumT = 0, tot = 0;
		while (t) {
			tot += t % 10;
			sumT = sumT * 10 + t % 10;
			t /= 10;
		}
		if (tot == n && sumT == i) cout << i << endl, flag = true;
	} 
	if (!flag) cout << -1;
	return 0;
} 
