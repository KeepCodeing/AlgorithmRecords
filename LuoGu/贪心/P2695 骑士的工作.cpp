#include <iostream>
#include <algorithm>
using namespace std;

// ��֮ǰ�Ǹ�ĸ�����������࣬�Ǹ���Ҫ��>������Ӧ����upper_bound��
// �����Ҫ��>=������Ӧ����lower_bound���Ӿ���������ж��ܲ��ܿ���
// ����������ǶԱ����ֵ�����о���you died!�ٴ��˸�!... 

int *heads, *man;
int main() {
	int n, m;
	int money = 0;
	cin >> n >> m;
	heads = new int[n + 5];
	man = new int[m + 5];
	for (int i = 0; i < n; i++) cin >> heads[i], money += heads[i];
	for (int i = 0; i < m; i++) cin >> man[i];
	sort(heads, heads + n);
	sort(man, man + m);
	int index = 0;
	int ans = 0;
	// �ӵ㣺ֻ�ܿ�<=��ͷ��������κ�һ��ͷ��ֵ���ܿ���ֵ�����
	// �����ܿ��� 
	if (heads[n - 1] > man[m - 1]) {
		cout << "you died!";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		index = lower_bound(man, man + m, heads[i]) - man;
		// �����������֮���������������ˣ�����STL�����ܲ����...������Ҳ����
		// ������������� 
		ans += man[index], man[index] = 0;
	}
	if (ans >= money) cout << ans;
	else cout << "you died!";
	delete[] heads, man;
	return 0;
}
