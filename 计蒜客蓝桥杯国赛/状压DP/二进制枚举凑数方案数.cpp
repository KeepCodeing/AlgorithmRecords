#include <iostream>
#define endl '\n'
using namespace std;

// ����n������Ȼ���ظ���ѡ����������������ǡ�ôյ�X�ķ����� 

const int N = 30;
int nums[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, ans, x, cnt = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < (1 << n); i++) {
		ans = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) ans += nums[j];
		}
		if (ans == x) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
/*
6 6
1 2 3 4 5 6
*/
