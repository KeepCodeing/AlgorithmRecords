#include <iostream>
using namespace std;
const int N = 3010;
typedef long long LL;
int nums[N];
// ���������ܻ�ܴ� 
LL f[N];
int main() {
	int n, m;
	cin >> n >> m;
	// ע���ʼ������Ȼ����ԶΪ0... 
	f[0] = 1;
	// ����ط�����ֱ�Ӹĳ�����ȫ���������� 
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = nums[i]; j <= m; j++) {
			f[j] += f[j - nums[i]];
		}
	}
	cout << f[m];
	return 0;
}
