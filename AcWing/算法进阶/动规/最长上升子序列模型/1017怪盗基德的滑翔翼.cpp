#include <iostream>
using namespace std;

// �����������������Ҫ�������½������У���������Ŷ�� 
// ״̬���ϣ���a[j]��a[i]����½�������
// ���Ա�ʾ��������½������еĳ���
// ״̬���� 

// �������Ȼ�Ǹ�����������е���Ŀ������Ŀ���ķ���������������������߷�
// �����߾��ǵ������������ѧ�У������߾�������������������С� 

const int N = 110, INF = 1e9;
int nums[N], f[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> nums[i];
		int res = 0;
		// ������
		for (int i = 1; i <= n; i++) {
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			res = max(f[i], res);
		}
		// �����ߣ�����������������о���
		for (int i = n; i >= 1; i--) {
			f[i] = 1;
			for (int j = n; j > i; j--) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			res = max(f[i], res);
		}
		cout << res << endl; 
	}
	return 0;
}

/*
3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10

6
6
9
*/
