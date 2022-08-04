#include <iostream>
#include <vector>
using namespace std;

// ���⣬��Ʒ������6�����룬�����ݻ�����������֮�ͣ���Ʒ��ֵ����������������һ����������кܶ������ô����ת���ɶ��ر�������
// ��Ȼ���ݷ�Χ��Сֱ�Ӹ��01����Ҳ�ǿ��Ե�... 

typedef pair<int, int > PII;
typedef long long LL;
const int N = 10, M = 1000 + 10;
int wei[N] = {1, 2, 3, 5, 10, 20};
int num, m = 0;
vector<PII > ele;
int f[M];
int main() {
	for (int i = 0; i < 6; i++) {
		cin >> num;
		// �����ݻ�������������֮�ͣ�����num���ж��ٸ����� 
		m += num * wei[i];
		// �����Ż� 
		for (int k = 1; k <= num; k <<= 1) {
			// �����ͼ�ֵ���
			ele.push_back(PII(k * wei[i], k * wei[i])); 
			num -= k;
		}
		if (num > 0) ele.push_back(PII(num * wei[i], num * wei[i]));
	}
	int vLen = ele.size();
	f[0] = 1;
	for (int i = 0; i < vLen; i++) {
		for (int j = m; j >= ele[i].first; j--) {
			f[j] += f[j - ele[i].second];
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) res += f[i];
	cout << "Total=" << res;
	return 0; 
}
