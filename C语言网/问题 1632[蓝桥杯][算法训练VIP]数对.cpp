#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �����̣�1 * 3 == 3 * 1ȴҪ������Σ�3 * 3 == 3 * 3ȴֻ�����һ��... 
void printNum(int x, int n, int num) {
	cout << x << " * " << n << " = " << num << endl;
}
vector<int > res;
int main() {
	int n;
	cin >> n;
	int tn = n;
	// ��Լ���������������Լ������һ������ 
	for (int i = 1; i <= n / i; i++) {
		// ��������ֱ������ģ������������������������������n=9��
		// ԭ��Ӧ�����һ��3*3�ģ�������Ϊ�����ж�i!=n/i����ֻ��
		// ���һ��3* 
		if (!(n % i)) {
			res.push_back(i); 
			if (i != n / i) res.push_back(n / i); 
		}
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) printNum(res[i], tn / res[i], tn);
	return 0;
}
