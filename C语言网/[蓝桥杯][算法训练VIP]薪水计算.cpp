#include <iostream>
#include <cstdio>
using namespace std;

// �鷳����.. 

int main() {
	int n;
	double m;
	scanf("%d%lf", &n, &m);
	double res = 0;
	// С�ڵ���40ֱ�ӳ� 
	if (n <= 40) res += n * m;
	// ����40С�ڵ���50�Ĳ����Ȱ�40�Ĳ�����������ٰѳ���40�Ĳ�������� 
	else if (n > 40 && n <= 50) res += (40 * m) + (n - 40) * 1.5 * m;
	// ͬ�ϣ�ֻ�������ﳬ��40�Ĳ���С�ڵ���50�Ĳ����ǹ̶��ģ�Ҳ����10.. 
	else res += (40 * m) + 10 * 1.5 * m + (n - 50) * m * 2;
	printf("%.2lf", res);
	return 0;
}
