#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ���ƺ���֪����ʽ��(���ֵ - ��Сֵ) / ���� + 1���ܵõ��Ȳ����е�����w������һ����Ϊ
// �����ֻ�ܱ���...��ô�Ÿ���Ȼ�������С�������ʹ���������..������Ӧ���ǲ����Լ�
// ����ģ���Ȼ���Ⱦ��������..��.. 

int main() {
	int n;	
	scanf("%d", &n);
	// �仹�ɻ�û�����ݷ�Χ��ô������w��û�뵽ֱ�Ӷ�̬����.. 
	int arr[n + 10];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int md = 0x3fffffff;
	sort(arr, arr + n);
	// ����С���ע��������� 
	for (int i = 1; i < n; i++) md = min(md, arr[i] - arr[i - 1]);
	if (md == 0) {
		printf("%d", n);
		return 0;
	}
	printf("%d", (arr[n - 1] - arr[0]) / md + 1);
	return 0;
}
