#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// ��һ�ݴ���׹����w����Ҫ�ǲ�������������С�������������ٿ�һ��.. 

const int N = 120;
int fz[N], fm[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
// ��n���������Լ������������С������Ҳ��һ����... 
int ngcd(int n) {
	if (n == 1) return abs(fm[0]);
	// ע���±��0��ʼ
	return gcd(fm[n - 1], ngcd(n - 1));
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int nlcm(int n) {
	if (n == 1) return fm[0];
	return lcm(fm[n - 1], nlcm(n - 1));
}
int main() {
	int cnt = 0;
	while (scanf("%d/%d", &fz[cnt], &fm[cnt]) != EOF) cnt++;
	int tfz = 0, tfm = nlcm(cnt);
	// ������ӳ�����С������/��ĸ�����ĺͣ�Ҳ���ǵ���ĸ����ͬʱ������ĸҲ����ͬ��������Ȼ����� 
	for (int i = 0; i < cnt; i++) tfz += (tfm / fm[i]) * fz[i];
	// ����ӷ�ĸ�����Լ����������ǵ����Լ�����ڣ�˵�������Խ���Լ�֣�ע����������Ǿ���ֵ�����Լ�� 
	// ��Ȼ����������� 
	int t = gcd(abs(tfm), abs(tfz));
	// ������ӿ���������ĸ����˵�����Ǹ����� 
	if (!(tfz % tfm)) printf("%d", tfz / tfm);
	// ����ͽ���Լ�֣������ƺ����Բ����жϷ��ӷ�ĸͬʱΪ�������w������������������û�е�w��Ҳ����˵-1/-3�����������ȷ�� 
	else printf("%d/%d", tfz / t, tfm / t);
	// ����ȫ�������ж� 
//	if (!(tfz % tfm)) printf("%d", tfz / tfm);
//	else if (!(tfm % tfz)) {
//		int t = gcd(abs(tfm), abs(tfz));
//		printf("%d/%d", tfz / t, tfm / t);
//	} else printf("%d/%d", tfz, tfm);
	return 0;
}
