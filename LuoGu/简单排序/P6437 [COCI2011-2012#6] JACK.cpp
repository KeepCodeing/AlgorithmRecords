#include <cstdio>
#include <algorithm>
using namespace std;

// ˮ����ɣ�����Ȼ��Ӵ�����ѡ... ׹��w������Ⲣ����̰�� 
// �ö�ά���ñ���д���£����ֲ����ܺܺõĽ�����⣬�����Ҫ�����ѡ����
// ��������ά���ñ����ǿ���ѡ1~k����Ҳ���ǲ�һ��ѡ����... 
// �������Ҫ�õ���ɢ������Ϊ���ķ�Χ�ܴ�...��ָ�ñ�����
// д�����϶����Թ���... 

const int N = 1e3 + 10;
int nums[N];
int f[N][10];
int main() {
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 3; k++) {
			for (int j = m; j >= nums[i]; j--) {
				// 245 216 36
				// 315 185
				f[j][k] = max(f[j][k], f[j - nums[i]][k - 1] + nums[i]);
			}
		}
		
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	//printf("%d", f[m][3]);
	return 0;
}
