#include <iostream>
using namespace std;
const int LEN = 18;

// ˼·����ö�����п��ܣ���������ȫ�������������ѼӼ�֦Ҳ�ܹ� 

int nums[LEN] = {1,16,81,256,625,1296,2401,4096,6561,10000,14641,20736,28561,38416,50625,65536,83521,104976};
int minCnt = 0x3FFFFFFF;
void dfs(int level, int num, int cnt, int used) {
	if (num <= 0) {
		if (num == 0) {
			minCnt = min(minCnt, cnt);
		}
		return;
	}
	for (int i = level; i >= 0; i--) { 
		// ��Ҫ�ļ�֦����Ȼn���󣬵������ö�ٵ��˺�С����������1
		// ����ͻῨ�� 
		// ��ô����Ҳ����˵����������ȫȫ�������仯����Ȼ�ص���������Ȼ�޷��õ����
		// �������ǿ��Լ�¼һ�����Ž⣬��˽��м�֦ 
		if (used >= minCnt) continue;
		dfs(i, num - nums[i], cnt + 1, used + 1);
	}
}

int main() {
	int n;
	cin >> n;
	int deepth = lower_bound(nums, nums + LEN, n) - nums;
	dfs(deepth, n, 0, 0);
	cout << minCnt;
	return 0;
}
