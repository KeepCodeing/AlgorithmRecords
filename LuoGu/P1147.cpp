#include <iostream>
using namespace std;
int main() {
	long n;
	cin >> n;
	// ��Ȼ������0 
	// ֮ǰд��i < n / 2,û������ȫ��i���Ե���n/2����21������һ�ֿ��ܾ���10,11, 
	for (int i = 0; i < n; i++) {
		long sn = i;
		// ����ͬ�� 
		for (int k = i + 1; k < n; k++) {
			sn += k;
			if (sn > n) break;
			if (sn == n) {
				cout << i << ' ' << k << endl;
				break;
			}
		}
	}
	return 0;
}
