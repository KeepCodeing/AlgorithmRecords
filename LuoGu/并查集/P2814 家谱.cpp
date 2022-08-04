#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

// ��Ĳ��鼯����ҪҪע������ַ��������ֵĻ�ת���������������map����һ����str->numһ����num->str 
// Ϊ��ȷ��Ψһ�Կ�����һ��id����������trie������Ĳ��� 

// ������ַ�����һ���ַ����������getchar()... 

const int N = 10, M = 5e5 + 10;
struct unionFind {
	int bin[M];
	unionFind ()  {
		for (int i = 1; i <= M; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] == x) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
};

map<int, string > mp;
map<string, int > pm;

char str[N], temp[N];
unionFind u;
int main() {
	int id = 1, father;
	while (true) {
		scanf("%s", &str);
		if (*str == '$') break;
		// ��Ҫ���⴦���¸��ַ��������ǳ����˸��ַ������Ͱ�����id����������Ȼ�����������ַ����ϲ��� 
		if (str[0] == '#') {
			// ������ַ����ĵ�һλͳһ��������ң������ʱ�������������� 
			str[0] = '*';
			// �������ַ����Ѿ������ˣ�ֱ��������id������͸�������id 
			if (!pm.count(str)) father = id, pm[str] = id, mp[id] = str, id++;
			else father = pm[str];
			//cout << father << endl;
		} else if (str[0] == '+') {
			str[0] = '*';
			// ����ط�д�ϲ���ʱ��д���ˣ��ǰ�id�ϲ���father�£����ǰ�father�ϲ���id��w������
			// �����˲�ѯʱ��ѯ���ַ�����Զ���Ǹ��ڵ� 
			if (!pm.count(str)) pm[str] = id, mp[id] = str, u.uni(id, father), id++;
			else u.uni(pm[str], father); 
		} else {
			str[0] = '*';
			//cout << pm[str] << endl;
			strcpy(temp, str + 1);
			cout << temp << ' ';
			strcpy(temp, mp[u.anc(pm[str])].c_str() + 1);
			cout << temp << endl;
		}
	}
	return 0;
}
