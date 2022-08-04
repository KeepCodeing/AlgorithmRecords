#include <iostream>
#include <cmath>
using namespace std;
// ���̣�ֻ�����»����������

// ����...����ȥ��..���������ȥ��...)

// û�����ѡ�����ޣ�������д����Ҳ������ȫ����д��д��ʱ����Ҫ�ǵ�ʲô��ѡ��ʲô��ѡ���б�

class Solution {
	public:
		int primeCnt = 0;
		bool isPrime(int num) {
			int k = (int)sqrt((double)num);
			for (int i = 2; i <= k; i++) {
				if (num % i == 0) return false;
			}
			return true;
		}
		void dfs(int level, int deepth, int nums[], int sumNum, int used, int n) {
			if (used == deepth) {
				primeCnt += (int)isPrime(sumNum);
				return;
			}
			// �����Ȼ��deepthд����ѡ�����ޣ�����������������Ϲ��...
			for (int i = level; i < n; i++) {
				dfs(i + 1, deepth, nums, sumNum + nums[i], used + 1, n);
			}
		}
		int resolve() {
			int n, k;
			cin >> n >> k;
			int *nums = new int[n];
			for (int i = 0; i < n; i++) cin >> nums[i];
			dfs(0, k, nums, 0, 0, n);
			delete[] nums;
			return primeCnt;
		}
};

int main() {
	Solution s = Solution();
	cout << s.resolve();
	return 0;
}
