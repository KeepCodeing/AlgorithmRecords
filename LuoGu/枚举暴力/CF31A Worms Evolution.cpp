#include <iostream>
using namespace std;

// ���ݷ�ΧС���������� 

// ����������ѭ�����Ǻ����׸��ģ���Ȼ���Ǵ���֮������¿��°�...
// �����̣�֮ǰд��i + 1, j + 1��ѭ���ƺ��ǿ��Ա�֤i��j��k��ͬ������
// WA�ˣ��ɹţ�����д��i == j || i == k || j == kȷʵ����������⣬����
// ������ĿҪ�����ai = aj + ak��������ak =...���������ߵ�ĩ· 

const int N = 110;
int nums[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i == j || i == k || j == k) continue;
				if (nums[i] == nums[j] + nums[k]) {
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
				// cout << nums[i] << ' ' << nums[j]  << ' ' << nums[k] << endl;
			}
		}
	}
	cout << -1 << endl;
	return 0;
} 
