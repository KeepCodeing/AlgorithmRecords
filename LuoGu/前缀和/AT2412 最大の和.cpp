#include <iostream>
using namespace std;

// ǰ׺�͵����þ��ǿ��ٲ���ĳ������[l,r]֮ǰ�ĺͣ�����ǰ׺�;Ͳ���
// ÿ�ζ�ȥ���ˣ�����Ҫע��߽����⣬�ȽϺõķ�����S0����Ϊ0��Ȼ���±�
// ��1��ʼ 

// ���ǵ�����ȫ���������int���ܴ治�£�������long�� 
long nums[100010];
int main() {
	// һ����˵����������100w����scanf��������cin 
	// �ر���C�����������ͬ�������Լӿ��д�ٶ� 
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	nums[0] = 0;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		// ǰ׺�͹�ʽ���е���Ƶĸо���������Ϊ��һ����Ϊ0����
		// �±��0��ʼ�����Բ����жϱ߽� 
		nums[i] = nums[i - 1] + num;
	}
	// for (int i = 1; i <= n; i++) cout << nums[i] << endl;
	// �����ж�����k�������������
	long ans = -1;
	for (int i = 1; i <= n - k; i++) {
		// ȡֵ��ʽ�����ǰ��޹������������� 
		ans = max(nums[i + k] - nums[i], ans);
	} 
	// ��Ϊû����ȫWA��... 
	cout << ans << endl;
	return 0;
}
