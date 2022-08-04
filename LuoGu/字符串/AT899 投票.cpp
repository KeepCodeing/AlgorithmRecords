#include <iostream>
#include <cstdio>
using namespace std;

// ��������mapˮ��ȥ��д��Trieû���κλ��� 

int son[1000][26], cnt[100], idx = 0;
void add(char str[]) {
	int p = 0;
	// ��ÿ���ַ�ӳ�䵽Trie�� 
	for (char i = 0; str[i]; i++) {
		// ����ǰ�ڵ�һ��Ψһ�ı�� 
		if (!son[p][str[i] - 'a']) son[p][str[i] - 'a'] = ++idx;
		p = son[p][str[i] - 'a'];
	}
	cnt[p]++;
}
int cwords(char str[]) {
	int p = 0;
	// �ҵ�Ҷ�ӽڵ㣬Ҷ�ӽڵ���������ַ����ĳ��ִ��� 
	for (char i = 0; str[i]; i++) p = son[p][str[i] - 'a'];
	return cnt[p];
}
char str[100], names[100][100];
int main() {
	int n, minCnt = -1, t;
	string res;
	cin >> n;
	// �����ַ����Լ��Ա��ַ������ִ��� 
	for (int i = 1; i <= n; i++) scanf("%s", &names[i]), add(names[i]);
	for (int i = 1; i <= n; i++) t = cwords(names[i]), res = minCnt < t ? minCnt = t, names[i] : res;
	printf("%s\n", res.c_str());
	return 0;
}
