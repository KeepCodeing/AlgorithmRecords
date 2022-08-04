#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

// �����Ҫ��һ����½������к�һ������������С�
// ��������������������з������ͳ������������У��������ֻ�ǻ��˸�˵�������Ƕ�Ӧ��Ŀ����������ض���ö�������������������������Ϊ����ϵͳֻ�ܴӸ��������أ�
// ����Ӹߵ�����������ص��Ѿ�������ˣ���ôʣ�����ľ���ֻ�������豸���ص���... 

const int N = 100000 + 10;
int nums[N], f1[N], f2[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	for (n = 1; cin >> nums[n]; n++);	
	n -= 1;
	// ע��������½��ͣ�����Ҫô�����鷴������Ҫô�ѱ��������� 
//	for (int i = n; i >= 1; i--) {
//		f1[i] = 1;
//		for (int j = i + 1; j <= n; j++) {
//			// ��������������� 
//			if (nums[i] >= nums[j]) f1[i] = max(f1[i], f1[j] + 1);
//		}
//	}
	// ������������� 
	for (int i = 1; i <= n; i++) {
		f2[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[i] > nums[j]) f2[i] = max(f2[i], f2[j] + 1);
		}
	}
	// ������������LISģ��Ҳ�У�����ע���±��1��ʼ... 
	reverse(nums + 1, nums + n + 1);
	
	for (int i = 1; i <= n; i++) {
		f1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[i] >= nums[j]) f1[i] = max(f1[i], f1[j] + 1);
		}
	}
	
	int res1 = 0, res2 = 0;
	for (int i = 1; i <= n; i++) {
		res1 = max(res1, f1[i]);
		res2 = max(res2, f2[i]);
	}
	cout << res1 << endl << res2;
	return 0;
}
