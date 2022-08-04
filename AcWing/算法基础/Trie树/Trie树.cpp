#include <iostream>
#include <cstdio>
using namespace std;

// Trie�������ã����ٲ���ĳ���ַ������ֵĴ��������ٲ����ַ�����
// ����ĺܶ��������ѭ����ɵģ�����Ҳ���Ըĳɵݹ�ʲô��... 

const int N = 100010;
// son[][]��ŵ�������ÿ���ڵ���ӽڵ�
// cnt��ŵ�����ÿ���ڵ��β�ĵ�����
// 0�Žڵ㼴�ǿսڵ�Ҳ�Ǹ��ڵ� 
// idx ��ʾ��ǰ�ڵ��ţ���Ϊ��ֻ���������Կ��Ա�֤�ڵ�Ψһ 
int son[N][26], cnt[N], idx = 0;

// ����һ���ַ���
void insertStr(char *str) {
	int p = 0;
	// ��while��׹�٣�������Ϊ��i��ԭ����������д���ǺϷ��ģ���ΪC������ַ���������
	// ����0 
	for (int i = 0; str[i]; i++) {
		// ���ַ�ӳ��Ϊ�����浽�ڵ��һ��26���ַ���Ҳ����˵ÿ�������26����֧ 
		int cur = str[i] - 'a';
		// ���ĳ���ڵ�����ַ�û�б�ӳ�䣬�ʹ�������ڵ� 
		if (!son[p][cur]) son[p][cur] = ++idx;
		// ����Ĳ�������ȡ������ڵ�ı�ţ�Ȼ�����´�����ڵ��֧ 
		p = son[p][cur];
	}
	// �Ѳ������ַ����Ľڵ������ַ������ִ��� 
	cnt[p]++;
} 
// ��ѯ�ַ������ֵĴ���
int query(char *str) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int cur = str[i] - 'a';
		if (!son[p][cur]) return 0;
		p = son[p][cur];
	}
	return cnt[p];
} 
char str[N];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		// ��������뼼�ɣ���ǰһ���ַ��Ϳո񿴳�һ���ַ�����������ͨ����ʽ������... 
		char code[2];
		scanf("%s%s", &code, &str);
		if (code[0] == 'I') insertStr(str);
		else cout << query(str) << endl;
	} 
	return 0;
}
/*
����������
5
I abc
Q abc
Q ab
I ab
Q ab
���������
1
0
1
*/
