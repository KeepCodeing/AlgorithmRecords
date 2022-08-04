#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

// 裸的并查集，主要要注意的是字符串和数字的互转，这个可以用两个map来，一个存str->num一个存num->str 
// 为了确保唯一性可以用一个id变量，类似trie和链表的操作 

// 这里的字符串第一个字符处理可以用getchar()... 

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
		// 需要特殊处理下父字符串，就是出现了父字符串，就把它的id保留下来，然后给后面的子字符串合并用 
		if (str[0] == '#') {
			// 把这个字符串的第一位统一，方便查找，输出的时候再做操作即可 
			str[0] = '*';
			// 如果这个字符串已经存在了，直接用它的id，否则就给它个新id 
			if (!pm.count(str)) father = id, pm[str] = id, mp[id] = str, id++;
			else father = pm[str];
			//cout << father << endl;
		} else if (str[0] == '+') {
			str[0] = '*';
			// 这个地方写合并的时候写反了，是把id合并到father下，不是把father合并到id下w，这样
			// 导致了查询时查询的字符串永远都是根节点 
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
