#include <iostream>
#include <cstdio>
using namespace std;

// �����Ӷκͣ�dpʵ�����֮ǰ������û�����Ķ������������������ȫû�������... 

const int N = 100000 + 10;
int nums[N];
int f[N];
int main() {
	// ��Сֵ����С׹��һ�Σ����������׹��һ��w... 
	int n, res = -0x3fffffff;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	f[0] = 0;
	// ��ʽ��w���������ǿ����뵽����ʽ�ӵģ��Ǿ��ǵ�ǰԪ�ص�ǰһ��λ�õ�����Ӷκ�+��ǰԪ�ص�ֵ�Ƿ�ȵ�ǰλ�ã�����
	// ����������Ӷκʹ�... 
	for (int i = 1; i <= n; i++) f[i] = max(f[i - 1] + nums[i], nums[i]);
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	cout << res << endl;
	return 0;
}

