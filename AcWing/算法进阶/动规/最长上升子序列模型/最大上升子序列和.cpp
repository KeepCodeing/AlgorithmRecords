#include <iostream>
using namespace std;

// ����f[i]Ϊ��nums[i]Ϊ��β��������������кͣ���ô���Ը���ǰ���֪ʶ�õ�f[i] = max(f[i], f[j] + nums[j]) 

const int N = 300 + 10;
int nums[N], f[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		f[i] = nums[i];
		for (int j = 1; j < i; j++) {
			// ע������Ķ��壺����nums[i]Ϊ��β�����������е����ͣ���ô�������ѡ��f[j]��Ҳ������nums[j]��β
			// �����������е����ͣ��������ֻ��ѡnums[i]�ˣ�֮ǰд��nums[j]�������û����״̬�Ķ���... 
			if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + nums[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) cout << f[i] << endl;
	cout << ans << endl;
	return 0;
}
