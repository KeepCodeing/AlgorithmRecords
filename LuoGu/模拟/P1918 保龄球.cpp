#include <iostream>
#include <map>
using namespace std;

// ������������Ͱ�ţ�����������̫����ܲ����У�����
// ����map 

map<int, int > mp;
int main() {
	int n;
	cin >> n;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		mp[t] = i;
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> t;
		// ������̣�ԭ�����Ǵ�����һ��λ�õ������λ�õ����û����
		// ����ĳ��λ�õ���������޴�...����Ϊ���ȫWA�ˣ����գ� 
		// �����ˣ��ֽ��˴�û��ɾ�������õ����... 
		if (mp.count(t)) cout << mp[t] << endl/*, mp.erase(t)*/;
		else cout << 0 << endl;
	}
	return 0;
} 
