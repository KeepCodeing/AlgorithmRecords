#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

// �ο����ͣ�https://blog.csdn.net/weixin_44077863/article/details/98037868 
// ���Ƿϵı�Ե����...��������µ������ˣ���Ҫ�õ�������ɢ���ļ��ɡ����������϶���������ͨ�߶��������ģ���Ϊ
// ��ͨ�߶����޷���ѯ���䣬ֻ�ܲ�ѯ�������ԡ���ô�����������ɢ���ĸ����ˣ�������ǽ�һ�����俴��һ���㣬Ȼ��
// ������������������Ϊ���Լ�����ô���õ���������һ�Ű��������ɸ��������������ж��´��ڶ��ٸ����伴�ɵõ�
// �𰸡���ô��������ν�һ������ӳ��ɵ㣬����������ǳ��� x[1]=1 x[2]=4 x[3]=6 x[4]=10��������ʽ�Ļ���������
// ������ζ��[1,4], [6, 10]����������㣬�������ﲢû�и���5��Ҳ���������������ǶϿ��ġ����������[1, 2], [3, 4]
// [5, 6]...�Ͳ�����ּ�ϣ�Ҳ����˵���Ǹɴཫ���������ֵ����1�ĵ㵥����ȡ������Ϊһ���µĵ㣬����ÿ������Ͷ���
// ��������... 

const int N = 1e5 + 10;
int lf[N], rg[N];
int nums[N * 4];
int main() {
	int T, n, cnt, res, temp;
	scanf("%d", &T);
	while (T--) {
		cnt = res = 0;
		scanf("%d", &n);
		// �����������������Ȼ�������ɢ�� 
		for (int i = 1; i <= n; i++) scanf("%d%d", &lf[i], &rg[i]), nums[cnt++] = lf[i], nums[cnt++] = rg[i];
		sort(nums, nums + cnt);
		temp = cnt = unique(nums, nums + cnt) - nums;
		// �ȱ�� 
		for (int i = 1; i < temp; i++) {
			if (nums[i] - nums[i - 1] > 1) nums[cnt++] = nums[i - 1] + 1;
		} 
		sort(nums, nums + cnt);
//		for (int i = 1; i <= n; i++)
	}
	return 0;
}
