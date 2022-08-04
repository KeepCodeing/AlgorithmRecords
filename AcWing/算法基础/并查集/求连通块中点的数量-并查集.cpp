#include <iostream>
#include <cstdio>
using namespace std;

// Ҫ��������ͳ��һ��������Ԫ�ظ��� 

struct unionFind {
	int bin[100010], size[100010];
	unionFind() {
		for (int i = 1; i <= 100010; i++) bin[i] = i, size[i] = 1;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// �����ͬʱ���¼��ϴ�С������Ҫע��ͬһ��
		// ���ϻ�����벻Ӱ�켯�ϴ�С
		 if (anc(x) != anc(y)) {
		 	// ���¼��ϴ�С 
		 	size[anc(y)] += size[anc(x)];
		 	// ��x���뵽y�� 
			bin[anc(x)] = anc(y);
		 }
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getSize(int x) {
		return size[anc(x)];
	}
};
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char op[5];
	int a, b;
	while (n--) {
		scanf("%s", &op);
		if (op[0] == 'C') {
			scanf("%d%d", &a, &b);
			u.uni(a, b);  
			// ��������뼼�ɣ����Է���Q1��Q2ֻ�еڶ�λ
			// ��ͬ�����Կ���ֻ�Աȵڶ�λ 
		} else if (op[1] == '1') {
			scanf("%d%d", &a, &b);
			printf("%s\n", u.ask(a, b) ? "Yes" : "No");
		} else {
			scanf("%d", &a);
			printf("%d\n", u.getSize(a));
		}
	}
	return 0;
}
/*
��������
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

�������
Yes
2
3
*/
