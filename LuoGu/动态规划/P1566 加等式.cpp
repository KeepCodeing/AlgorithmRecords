#include <iostream>
#include <cstdio>
using namespace std;

// �������£�m��Ԫ�ظ�����x��Ҫ�յ����������ݻ�����x[i]�ǿ����õ�����
// ��ΪҪ�յ������ܺͿ����õ�����ͬ����������Ҫ�ж��� 

// ˵�Ǽ򵥣�����̫�����˵��˰���...���Ժ�����������Ӧ����д�����ģ�壬Ȼ�����ģ��һ���ļ����� 

// ׹��ww������... 

const int M = 35, N = 1010;
int nums[M];
long long f[N];
int main() {
	int T;
	scanf("%d", &T);
	int m, res;
	while (T--) {
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) cin >> nums[i];
		res = 0;
		for (int k = 1; k <= m; k++) {
			// ��ÿ���������01���������� 
			fill(f, f + m + 1, 0);
			f[0] = 1;
			for (int i = 1; i <= m; i++) {
				for (int j = nums[k]; j >= nums[i]; j--) {
					// һֱ�������û�����ѡ�����͵�ǰ��������nums[i]��ʾѡ��������1,2,3��nums[k]
					// ��ʾ��ǰ��������3����Ϊ�����ѡ������Ҫ�յ���������ͬ����������Ҫ�Ӹ����� 
					if (nums[i] != nums[k]) f[j] += f[j - nums[i]];
				}
			}
			res += f[nums[k]];
		}
		cout << res << endl;
	}
	return 0;
}
