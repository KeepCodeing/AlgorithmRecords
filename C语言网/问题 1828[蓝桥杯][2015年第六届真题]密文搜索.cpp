#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<string > s;
int main() {
	// ��೤��Ϊ8�������б�Ҳ����˵���԰�ԭ���зֳ�
	// ��������Ϊ8�����ַ�����Ȼ�����������ȫ����
	// ȥ�Աȣ�Ϊ�˷��㣬���԰����ַ������뵽һ��set�� 
	string str;
	cin >> str;
	int sLen = str.size();
	// �����ƺ�������ȷ��ÿ���ƶ�һλ��ȡ���ַ����ķ��� 
	for (int i = 0; i + 7 < sLen; i++) {
		s.insert(str.substr(i, 8)); 
	}
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string temp;
		cin >> temp;
		sort(temp.begin(), temp.end());
		do {
			// ��Ϊ��һ�����в�����жԱȣ�������do while 
			if (s.count(temp)) ans++;
		} while(next_permutation(temp.begin(), temp.end()));
	}
	cout << ans;
	return 0;
}
