#include <iostream>
#include <cstdio>
using namespace std;

// Ħ��ͶƱ��������̸�� 

int main() {
	int n;
	scanf("%d", &n);
	int vote = 0, res = 0;
	int t;
	while (n--) {
		scanf("%d", &t);
		// Ĭ��һ������ 
		if (!vote) res = t;
		// ���ֱ����������Ȩ�ؼ�һ 
		if (res != t) vote--;
		// ����Ȩ�����ӣ������������һ������������ 
		else vote++;
	}
	printf("%d", res);
	return 0;
}
