#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// �����ϸ�����һ���������ε�������������������ַ���������ǰ���ַ�����Ӧ������
// ��ȥ��һ������...

// ���������Ӧ�ÿ�����Trie����������Ϊ���Ǻõģ�û���κλ��� 

map<string, int > mp;
map<string, string > pm;
vector<string > vec, res;
string solve(string str) {
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) str[i] = tolower(str[i]);
	sort(str.begin(), str.end());
	return str;
}
int main() {
	string str, temp;
	while (cin >> str) {
		if (str == "#") break;
		temp = solve(str);
		mp[temp]++;
     // ʡȥ�ڶ���������＼��ֱ�Ӷ࿪��map���������ַ���ԭ�ַ���Ӧ����
		pm[str] = temp;
		vec.push_back(str); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
    // ͨ��ԭ�ַ�ȡ�������ַ�����ͨ�������ַ�ѯ������ַ����ִ���
		if (mp[pm[vec[i]]] != 1) continue;
		res.push_back(vec[i]); 
	}
	sort(res.begin(), res.end());
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << res[i] << endl;
		//if (i != rLen - 1) cout << endl;
	}
	return 0;
} 
