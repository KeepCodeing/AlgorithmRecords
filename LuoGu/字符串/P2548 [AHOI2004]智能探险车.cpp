#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// м��Ŀ�����˰������������˼����ʵ������ͬ�ַ������
// ��ͬ�ַ������* 
// һ��ʼ���ø�setͳ�ƣ���ϸ���¾�֪���������ˣ����ǵ���
// mapͳ�Ƶ��ʸ��� 

map<string, int > mp;
vector<string > v;
int main() {
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			mp[temp]++;
			// �Ѽ�������������������set�ģ�����set�����˲����� 
			// �ѵ�һ����Ϊ���б���Ȼ���ж����key 
			// !count(v.begin(), v.end(), temp) && ֮ǰΪ�˱�֤��Ψһ���жϣ�����û��Ҫ 
			if (i == 0) {
				v.push_back(temp); 
			}
		}
	}
	int vLen = v.size();
	for (int i = 0; i < vLen; i++) {
		if (mp[v[i]] == m) cout << v[i];
		else cout << '*';
		if (i != vLen - 1) cout << ' ';
	}
	return 0;
}
