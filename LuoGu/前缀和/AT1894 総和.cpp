#include <iostream>
using namespace std;
long long nums[100010];

// ����һ���ⲻ̫һ������������ƻ������� 

int main() {
	int n, k;
	cin >> n >> k;
	int temp;
	nums[0] = 0;
	for (int i = 1; i <= n; i++) cin >> temp, nums[i] = nums[i - 1] + temp;
	// ���ݺܴ󣬱��������޷��ţ����ǿ��ǵ���һ��ǰ׺�ͼ�ǰһ��ǰ׺��
	// ���ܳ��ָ�ֵ�������ָĻ����� 
	long long ans = 0;
	// ����k-1���������һ��Ԫ���㲻�������üӻ��� 
//	for (int i = 1; i <= n - k + 1; i++) {
//		// ����һ����ȱ仯�ĵط���������k-1�����ֱ�Ӽ�k�Ͷ����һ��
//		// Ԫ�أ�����ĿҪ�����������ǰ׺�ͣ������Ǵ�i~k��ǰ׺�ͣ�����
//		// ���ﻹҪ��ǰһ��ǰ׺�ͼ��� 
//		ans += nums[i + k - 1] - nums[i - 1];
//	}
	// ��������ѭ����д���е��ƣ��ȽϺõ�д����iֱ�Ӵ�k��ʼ
	for (int i = k; i <= n; i++) {
		ans += nums[i] - nums[i - k];
	} 
	cout << ans << endl;
	return 0;
}
