#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
int nums[N], f[N * 100];

// 01����... 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, sum = 0, half;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
	}
	// *������һ��*���������ﻹ�ü�һ����֪��Ϊʲô���ܵ���..�� 
	half = sum / 2 - 1;
	for (int i = 0; i < n; i++) {
		for (int j = half; j >= nums[i]; j--) {
			f[j] = max(f[j], f[j - nums[i]] + nums[i]);
		}
	}
	// �����Ĵ�Ӧ����f[�ݻ�]��������f[��Ʒ����]... 
	cout << f[half] << endl;
	return 0;
}
