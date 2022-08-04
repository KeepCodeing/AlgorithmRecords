#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;

// ���ǽ����ṹ��+STL��ɰգ����������ʽͨ��C������������ 
// ����д̫���������ˣ����ǲ�����... 
// �����������������˼·������ 

struct poke {
	// ת��Ϊ���ֶԱ� 
	int num, flower;
	// ����õ��ַ� 
	char outNum, outFlower;
	poke (int n = 0, int f = 0) {
		num = n, flower = f;
	}
	bool operator<(const poke& p) {
		if (num != p.num) return num < p.num;
		return flower < p.flower;
	}
};
poke pk[5];
int main() {
	char flower, num;
	char temp;
	for (int i = 0; i < 5; i++) {
		scanf("%c%c", &num, &flower);
		// ��10�������⴦����Ϊ�������ֶ���һλ�ģ���10���ַ�������λ 
		if (num == '1' && flower == '0') {
			pk[i].num = 10;
			// 10�Ƚ��������� 
			pk[i].outNum = 't';
			temp = getchar();
			pk[i].outFlower = temp;
			if (temp == 'd') pk[i].flower = 0;
			else if (temp == 'c') pk[i].flower = 1;
			else if (temp == 'h') pk[i].flower = 2;
			else if (temp == 's') pk[i].flower = 3;
			continue;
		}
		// ����ĸת��Ϊ���� 
		pk[i].outNum = num;
		if (num >= '2' && num <= '9') pk[i].num = (int)(num - '0');
		else if (num == 'J') pk[i].num = 11;
		else if (num == 'Q') pk[i].num = 12;
		else if (num == 'K') pk[i].num = 13;
		else if (num == 'A') pk[i].num = 14;
		// ����ɫת��Ϊ���� 
		pk[i].outFlower = flower;
		if (flower == 'd') pk[i].flower = 0;
		else if (flower == 'c') pk[i].flower = 1;
		else if (flower == 'h') pk[i].flower = 2;
		else if (flower == 's') pk[i].flower = 3;
	}
	// �������
	sort(pk, pk + 5);
	for (int i = 0; i < 5; i++) {
		// 10�����⴦�� 
		if (pk[i].outNum == 't') {
			cout << 10 << pk[i].outFlower;
			continue;
		}
		cout << pk[i].outNum << pk[i].outFlower;
		if (i != 4) cout << ' ';
	}
	return 0;
}
