#include <cstdio>
#include <algorithm>

using namespace std;

// ��������ֵ��������STL�ܲ��ܹ���������ƺ����ݺ�ˮ�� 

// ��̫���е����ӣ������� 

const int M = 100010;
int nums[M];
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	int lf, ri;
	while (m--) {
		scanf("%d%d", &lf, &ri);
		// printf("%d %d\n", *(nums + lf), *(nums + ri));
		nth_element(nums + lf, nums, nums + ri);
		//puts("");
		//for (int i = 1; i <= n; i++) printf("%d ", nums[i]);
		printf("---%d---\n", nums[lf]);
	}
	return 0;
}
