#include <iostream>
#include <algorithm>
using namespace std;

// ����һ�㣬����copy����Ҫ���ṩһ��������������Լ�������Ĺ���
// �о͸���Ǿ���ֵ����ô�������ʱ��Ҫ��ԭ������ԭ�ֵ�֪���±꣬����
// �ǳ��鷳
 
bool cmp(int a, int b) {
	return abs(a) > abs(b);
}
int nums[110];

int main() {
	int n;
	while (cin >> n) {
		if (!n) break;
		for (int i = 0; i < n; i++) cin >> nums[i];
		sort(nums, nums + n, cmp);
		for (int i = 0; i < n; i++) {
			cout << nums[i];
			if (i != n - 1) cout << ' ';
		}	
		cout << endl;
	}
	return 0;
}
