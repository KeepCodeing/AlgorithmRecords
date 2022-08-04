#include <iostream>
#include <cstdio>
using namespace std;

// ��ʵ������vjudgeҲ��������⣬dp�����⣬��ǰ�������ɵģ�����ȫȫ��
// ����...
// ���һ���������ߣ��ߵ�����һ��ֻ�������㣬���������ʹ�����������
// ����С
// ��Ϊ���һ��Ԫ�ز������߹����ĵ㣬������Щ��ĳ�ʼֵ����������������˳��
// �Ǵ��µ��� 
// ״̬ת�Ʒ��̣�f[i][j] = max{f[i + 1][j], f[i + 1][j + 1]} + nums[i][j] 
// �����������ֵ��vjudge�����Сֵ... 

typedef long long LL;
const int N = 1010;
int nums[N][N];
LL f[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &nums[i][j]);
			if (i == n) f[i][j] = nums[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++){
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + nums[i][j];
		}
	}
	// ����д����&f[1][1]�����˰������.. 
	printf("%d", f[1][1]);
	return 0;
}
