#include <iostream>
#define endl '\n'
using namespace std;

const int N = 100 + 10;
int nums[N], f[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	// �����Ż���ֻ����һ��LIS�ͷ���LIS��Ȼ��ö���е���max(f1[i] + f2[i] - 1)...
	// Ϊʲô���������أ���Ϊ���ǵ�״̬�������f[i]Ϊnums[i]��βʱ��LIS���ȣ��ظ�������û��Ҫ��... 
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	
	// ��iΪ���ģ���[1, k]�ĵ��������У�����[k, n]�ĵݼ������У�Ȼ��
	// [max(f1) + max(f2)]������iΪ������������¶����ˣ���ô��n��ȥ
	// �͵õ�������Ҫȥ�����˵�������ע������k�����ط����õ��ˣ�����
	// ��Ϊk-1 < k > k + 1 
	
	int lis = 0, lms = 0, ans = 9999999;
	for (int k = 1; k <= n; k++) {
		lis = 0, lms = 0;
		// ������������� 
		for (int i = 1; i <= k; i++) {
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			lis = max(lis, f[i]);
		} 
		// ����½������У���ʵ���Ǵ�β����ʼ������������У���������
		// �����Է������ַ���ĵ����������ҿ��ǵݼ�...����
		// ������ΪҪ��������ÿ�ν����鷴�������Բ�����
		for (int i = n; i >= k; i--) {
			f[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			lms = max(lms, f[i]);
		} 	
		// ע�����Ҫ-1��������Ϊnums[k]�Ĺ��׻ᱻ�����Σ���������һ������һ���������ӣ�lis = 1, lms = 1��Ҳ����
		// ˵ֻ��k��ʱ���������������2������Ҫ��ȥ����ظ����ֵ 
		ans = min(ans, n - (lis + lms - 1));
	}
	cout << ans << endl;
	return 0;
}
