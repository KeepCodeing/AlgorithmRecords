#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Trie��д����ͬ����Ҫ��ԭ�ַ������������ַ���Ӧ������ʡȥһ������
// �������ǰ�������������ַ��浽���Ȼ��ͳ������ַ������ֵĴ���
// ����һ�ξ����޷�����ɵ��ַ��� 

const int N = 1e5 + 10;
int son[N][26], cnt[N], id = 0;
map<string, string > mp;
// Trie������ 
string getStr(string str) {
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) str[i] = tolower(str[i]);
	return str;
}
void add(string str) {
	int p = 0, sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) son[p][cur] = ++id;
		p = son[p][cur];
	}
	cnt[p]++;
}
bool fd(string str) {
	int p = 0, sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int cur = str[i] - 'a';
		// ������п��ޣ�׼ȷ��˵���ַǷ��ַ����Ŀ�����Ϊ0% 
		// if (!son[p][cur]) return false;
		p = son[p][cur];
	}
	// �ж�������ַ����Ƿ�ֻ������һ�� 
	return cnt[p] == 1;
}
int main() {
	string str, temp;
	while (cin >> str) {
		if (str == "#") break;
		temp = getStr(str);
		sort(temp.begin(), temp.end());
		// ���������ַ�����ԭ�ַ�������ӳ�䣬��������ʡȥһ������ 
		mp[str] = temp;
		add(temp);
	}
	// ѹ��ʲô����ȫû��Ҫ�� 
	for (map<string, string >::iterator it = mp.begin(); it != mp.end(); it++) {
		// ���key�ַ�����������ʽ��value��ֻ���ֹ�һ�Σ���ô����ַ�������Ψһ�� 
		if (fd(it->second)) cout << it->first << endl;
	}
	return 0;
} 
