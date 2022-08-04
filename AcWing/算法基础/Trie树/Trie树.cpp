#include <iostream>
#include <cstdio>
using namespace std;

// Trie树的作用：快速查找某个字符串出现的次数，快速插入字符串。
// 下面的很多操作都是循环完成的，所以也可以改成递归什么的... 

const int N = 100010;
// son[][]存放的是树中每个节点的子节点
// cnt存放的是以每个节点结尾的单词数
// 0号节点即是空节点也是根节点 
// idx 表示当前节点标号，因为其只能自增所以可以保证节点唯一 
int son[N][26], cnt[N], idx = 0;

// 插入一个字符串
void insertStr(char *str) {
	int p = 0;
	// 用while会坠毁，暂且认为是i的原因，另外这种写法是合法的，因为C里面的字符串结束符
	// 就是0 
	for (int i = 0; str[i]; i++) {
		// 将字符映射为整数存到节点里，一共26个字符，也就是说每层最多有26个分支 
		int cur = str[i] - 'a';
		// 如果某个节点这个字符没有被映射，就创建这个节点 
		if (!son[p][cur]) son[p][cur] = ++idx;
		// 这里的操作就是取出这个节点的标号，然后重新从这个节点分支 
		p = son[p][cur];
	}
	// 把产生了字符串的节点标记下字符串出现次数 
	cnt[p]++;
} 
// 查询字符串出现的次数
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
		// 奇妙的输入技巧：将前一个字符和空格看成一个字符串，而不是通过格式化输入... 
		char code[2];
		scanf("%s%s", &code, &str);
		if (code[0] == 'I') insertStr(str);
		else cout << query(str) << endl;
	} 
	return 0;
}
/*
输入样例：
5
I abc
Q abc
Q ab
I ab
Q ab
输出样例：
1
0
1
*/
