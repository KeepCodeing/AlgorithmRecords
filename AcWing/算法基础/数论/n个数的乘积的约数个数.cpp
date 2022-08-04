#include <iostream>
#include <map>
using namespace std;

// ����n��������ai�����������Щ���ĳ˻���Լ���������𰸶�10^9+7ȡģ��

// Լ��������������һ����Ȼ��N�����Խ���ֽ�����ɸ������ĳ˻���Ҳ���������ӣ�
// �������Ȼ��N��Լ�������͵���ÿ�������ӵĸ�����һ�ĳ˻�.
//�������ǿ�����һ��Ͱ������������ÿ�������������������չ�ʽ��������� 

// 6����������2�� 3��Լ��������(1 + 1)*(1 + 1) = 4��Լ��Ϊ
// 1, 2, 3, 6 

const int mod = 1e9 + 7;
// ����������Ͱ 
map<int, int > bucket;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		// �ֽ�������
		for (int i = 2; i <= x / i; i++) {
			while (!(x % i)) {
				// ͳ�������ӵĸ��� 
				bucket[i]++;
				x /= i;
			}
		}	
		// ���������ܳ�������������
		if (x > 1) bucket[n]++; 
	}
	int ans = 1;
	for (map<int, int >::iterator it = bucket.begin(); it != bucket.end(); it++) {
		ans *= (it->second + 1) % mod;
	}
	cout << ans;
	return 0;
}
/*
��������
3
2
6
8

�������
12
*/
