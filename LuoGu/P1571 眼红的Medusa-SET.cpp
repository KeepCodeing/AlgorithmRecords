#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// Ӧ�ÿ����ø�������ĳ��Ԫ���Ƿ���ֹ������������Ͱ�ŵ�˼�� 
// ���������ݷ�Χ��̫���ˣ�������Ͱ�ţ�����Ӧ�ÿ�����set

// ׹�٣�û�뵽��һ��map���Ԫ���Ƿ���ֹ���Ȼ��ȥ��һ������
// �� 

map<long long, int> mp;
vector<long long > v;
int main() {
	int n, m;
	cin >> n >> m;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp); 
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		mp[temp] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (mp[v[i]]) {
			cout << v[i];
			if (i != n - 1) cout << ' ';
		}
	}
	return 0;
}
